//
//  main.cpp
//  aa_lab5
//
//  Created by Антон Тимонин on 30.01.2020.
//  Copyright © 2020 Антон Тимонин. All rights reserved.
//



#include "matrixObject.hpp"

using namespace std;

int x = 0;
vector <vector <int> > objectTimeStayingAtQueue(4);


class Conveyor {
private:
    size_t elementsCount;
    size_t queuesCount;
    size_t averegeTime;
    const size_t delayTime = 3;
    
    size_t getCurTime() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    
    void doObjectLinearWork(matrixObject& curObject, size_t queueNum) {
        size_t start = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": START - " << start << endl;
        
        curObject.addUpMatrix(0, curObject.sizeMatrix/3);
        
        size_t end = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": STOP -  " << end << endl;
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": TIME -  " << end - start << endl;
    }
    
    void doObjectLinearWork2(matrixObject& curObject, size_t queueNum) {
        size_t start = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": START - " << start << endl;
        
        curObject.addUpMatrix(curObject.sizeMatrix / 3, 2 * curObject.sizeMatrix / 3);
        
        size_t end = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": STOP -  " << end << endl;
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": TIME -  " << end - start << endl;
    }
    
    void doObjectLinearWork3(matrixObject& curObject, size_t queueNum) {
        size_t start = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": START - " << start << endl;
        
        curObject.addUpMatrix(2 * curObject.sizeMatrix / 3, curObject.sizeMatrix);
        
        size_t end = getCurTime();
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": STOP -  " << end << endl;
//        cout << "Object #" << curObject.number <<  " from Queue #" << queueNum << ": TIME -  " << end - start << endl;
        //resTimeFile
    }
    
public:
    Conveyor(size_t elementsCount, size_t queuesCount, size_t milliseconds) : elementsCount(elementsCount), queuesCount(queuesCount), averegeTime(milliseconds) {}
    
    void executeLinear() {
        
        queue <matrixObject> objectsGenerator;
        
        for (size_t i = 0; i < elementsCount; ++i) {
            objectsGenerator.push(matrixObject(1038, -20, 200, i + 1));
        }
        
        vector <matrixObject> objectsPool;
        
        while (objectsPool.size() != elementsCount) {
            matrixObject curObject = objectsGenerator.front();
            objectsGenerator.pop();
            
            for (size_t i = 0; i < queuesCount; ++i) {
                if (i == 0) {
                    doObjectLinearWork(curObject, i);
                } else if (i == 1) {
                    doObjectLinearWork2(curObject, i);
                } else if (i >= 2) {
                    doObjectLinearWork3(curObject, i);
                }
                
            }
            
            objectsPool.push_back(curObject);
        }
    }
    
private:
    void doObjectParallelWork(matrixObject curObject, queue <matrixObject>& queue, size_t queueNum, mutex& mutex) {
        size_t start = getCurTime();
        
        curObject.addUpMatrix(0, curObject.sizeMatrix/3);
        
        mutex.lock();
        queue.push(curObject);
        mutex.unlock();
        
        size_t end = getCurTime();
//        cout << "Object" << curObject.number <<  "; Queue " << queueNum << "; Time  " << end - start << endl;
        objectTimeStayingAtQueue[queueNum + 1].push_back(-end);
    }
    
    void doObjectParallelWork1(matrixObject curObject, queue <matrixObject>& queue, size_t queueNum, mutex& mutex) {
        size_t start = getCurTime();
        curObject.addUpMatrix(curObject.sizeMatrix / 3, 2 * curObject.sizeMatrix / 3);
        
        mutex.lock();
        queue.push(curObject);
        mutex.unlock();
        
        size_t end = getCurTime();
//        cout << "Object" << curObject.number <<  "; Queue " << queueNum << "; Time  " << end - start << endl;
        objectTimeStayingAtQueue[queueNum + 1].push_back(-end);
    }
    
    void doObjectParallelWork2(matrixObject curObject, queue <matrixObject>& queue, size_t queueNum, mutex& mutex) {
        size_t start = getCurTime();
        
        curObject.addUpMatrix(2 * curObject.sizeMatrix / 3, curObject.sizeMatrix);
        
        mutex.lock();
        queue.push(curObject);
        mutex.unlock();
        
        size_t end = getCurTime();
//        cout << "Object" << curObject.number <<  "; Queue " << queueNum << "; Time  " << end - start << endl;
        objectTimeStayingAtQueue[queueNum + 1].push_back(-end);
    }
    
public:
    void executeParallel() {
        
        queue <matrixObject> objectsGenerator;
        
        for (size_t i = 0; i < elementsCount; ++i) {
            objectsGenerator.push(matrixObject(1038, -20, 200, i + 1));
        }
        
        vector <thread> threads(3);
        vector <queue <matrixObject> > queues(3);
        queue <matrixObject> objectsPool;
        vector <mutex> mutexes(4);
        size_t prevTime = getCurTime() - delayTime;
        
        while (objectsPool.size() != elementsCount) {
            size_t curTime = getCurTime();
            
            if (!objectsGenerator.empty() && prevTime + delayTime < curTime) {
                matrixObject curObject = objectsGenerator.front();
                objectsGenerator.pop();
                queues[0].push(curObject);
                
                prevTime = getCurTime();
                
                objectTimeStayingAtQueue[0].push_back(-prevTime);
            }
            
            for (int i = 0; i < queuesCount; ++i) {
                if (threads[i].joinable()) {
                    threads[i].join();
                }
                if (!queues[i].empty() && !threads[i].joinable()) {
                    mutexes[i].lock();
                    matrixObject curObject = queues[i].front();
                    queues[i].pop();
                    mutexes[i].unlock();
                    
                    size_t start = getCurTime();
                    objectTimeStayingAtQueue[i][objectTimeStayingAtQueue[i].size() - 1] += start;
                    
                    if (i == 0) {
                        threads[i] = thread(&Conveyor::doObjectParallelWork, this, curObject, ref(queues[i + 1]), i, ref(mutexes[i + 1]));
                    } else if (i == 1) {
                        threads[i] = thread(&Conveyor::doObjectParallelWork1, this, curObject, ref(queues[i + 1]), i, ref(mutexes[i + 1]));
                    } else if (i == queuesCount - 1) {
                        threads[i] = thread(&Conveyor::doObjectParallelWork2, this, curObject, ref(objectsPool), i, ref(mutexes[i + 1]));
                        
                    }
                }
            }
        }
        
        for (int i = 0; i < queuesCount; ++i) {
            if (threads[i].joinable()) {
                threads[i].join();
            }
        }
    }
    
};

int main(int argc, const char * argv[]) { // 1038
    
    int elementsCount = 1000;

    Conveyor conveyor(elementsCount, 3, 5);

    auto start = std::chrono::steady_clock::now();
    
    conveyor.executeParallel();
//    conveyor.executeLinear();
    
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
    cout << "Сonveyor par" << ", time: " << duration.count() << " milliseconds" <<  endl;
    
    cout << "\n\n\n";
    
    start = std::chrono::steady_clock::now();
        
//        conveyor.executeParallel();
        conveyor.executeLinear();
        
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
    

    cout << "Сonveyor lin" << ", time: " << duration.count() << " milliseconds" <<  endl;
    cout << "\nPROGRAMM ENDED!\n";
    
    return 0;
}
