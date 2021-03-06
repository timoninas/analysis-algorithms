import re

def FindGroups(text):

    text += "*******"

    i = 0

    while(1):

        if len(text) <= i + 10:
            break

        tmpStroke = text[i: i + 10]
        tmpStroke = tmpStroke.upper()

        match = re.match(r'(МТ|ИУ|РЛ|ФН|СМ|Э|РК|БМТ|ИБМ|Л|СГН|РКТ|АК)(10|11|12|[1-9])-((10|11|12|[1-9]))[1-6][бмБМ]?',
                          tmpStroke)

        if match != None:

            print(match[0])

        i += 1


if __name__ == '__main__':
    text = '''
    кафедры ИУ7 группы: ИУ7-52б, ИУ7-92б, ИУ15-12м, ИИУУ7-82б, ИИУ7-82б
    а также не забываем гениальных гениев из ибм12-12м, ибм13-13м,
    а вы знали про людей из ЭзкЭ3-12м,Э6-12, Э09-12Б, Э7-52б
    ИУ7, ИУ6, РК1, РЛ4, и не только. А именно РК1-88 и РК1-86м, РК1-46м, РК1-86б
'''
    FindGroups(text)
