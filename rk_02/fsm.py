

def GetFSM(stroke):

    state = 1
    groupName = ''

    for value in stroke:
        # print(state)
        # print("value = " + value)
        if state == 1:
            if value  ==  'М':
                state = 2
            elif value == 'С':
                state = 4
            elif value == 'И':
                state = 6
            elif value == 'Э':
                state = 14
            elif value == 'Р':
                state = 11
            else:
                break
            groupName += value

        elif state == 2:
            if value == 'Т':
                state = 14
            else:
                break
            groupName += value

        elif state == 4:
            if value == 'М':
                state = 14
            else:
                break
            groupName += value

        elif state == 6:
            if value == 'Б':
                state = 7
            elif value == 'У':
                state = 14
            else:
                break
            groupName += value

        elif state == 11:
            if value == 'К':
                state = 14
            elif value == 'Л':
                state = 14
            else:
                break
            groupName += value

        elif state == 7:
            if value == 'М':
                state = 14
            else:
                break
            groupName += value

        elif state == 14:
            if value.isdigit() and int(value) in [2,3,4,5,6,7,8] :
                state = 15
            elif value.isdigit() and int(value) == 1:
                state = 16
            else:
                break
            groupName += value

        elif state == 15:
            if value == '-':
                state = 19
            elif value == 'И':
                state = 18
            else:
                break
            groupName += value

        elif state == 16:
            if value.isdigit() and int(value) in [1,2]:
                state = 17
            elif value == 'И':
                state = 18
            elif value == '-':
                state = 19
            else:
                break
            groupName += value

        elif state == 17:
            if value == 'И':
                state = 18
            elif value == '-':
                state = 19
            else:
                break
            groupName += value

        elif state == 18:
            if value == '-':
                state = 19
            else:
                break
            length += 1

        elif state == 19:
            if value.isdigit() and int(value) in [1]:
                state = 20
            elif value.isdigit() and int(value) in [2,3,4]:
                state = 21
            elif value.isdigit() and int(value) in [5,6,7,8]:
                state = 22
            elif value.isdigit() and int(value) in [9]:
                state = 23
            else:
                break
            groupName += value

        elif state == 20:
            if value.isdigit() and int(value) in [1,2]:
                state = 24
            elif value.isdigit() and int(value) in [3,4,5,6]:
                state = 25
            else:
                break
            groupName += value

        elif state == 21:
            if value.isdigit() and int(value) in [1,2,3,4,5,6]:
                state = 26
            else:
                break
            groupName += value

        elif state == 22:
            if value.isdigit() and int(value) in [1,2,3,4,5,6]:
                state = 27
            else:
                break
            groupName += value

        elif state == 23:
            if value.isdigit() and int(value) in [1,2,3,4,5,6]:
                state = 28
            else:
                break
            groupName += value

        elif state == 24:
            if value == "М":
                state = 29
            elif value == "Б":
                state = 30
            elif value.isdigit() and int(value) in [1,2,3,4,5,6]:
                state = 31
            else:
                break
            groupName += value

        elif state == 25:
            if value == "М":
                state = 32
            elif value == "Б":
                state = 33
            else:
                break
            groupName += value

        elif state == 26:
            if value == "М":
                state = 34
            elif value == "Б":
                state = 35
            else:
                break
            groupName += value

        elif state == 27:
            if value == "Б":
                state = 36
            else:
                break
            groupName += value

    # print("State = " + str(state))
    # print("Group = " + str(groupName))

    if state >= 24 and state <= 36:
        return groupName
    else: return ''

def FindGroups(text):

    groups = []
    text += "*******"

    i = 0

    while(1):

        if len(text) <= i + 10:
            break

        tmpStroke = text[i: i + 10]
        tmpStroke = tmpStroke.upper()

        group = GetFSM(tmpStroke)
        if group != '':
            groups.append(group)

        i += 1

    return groups

if __name__ == '__main__':
    text = '''
    кафедры ИУ7 группы: ИУ7-52б, ИУ7-92б, ИУ15-12м, ИИУУ7-82б, ИИУ7-82б
    а также не забываем гениальных гениев из ибм12-12м, ибм13-13м,
    а вы знали про людей из ЭзкЭ3-12м,Э6-12, Э09-12Б, Э7-52б
    ИУ7, ИУ6, РК1, РЛ4, и не только. А именно РК1-88 и РК1-86м, РК1-46м, РК1-86б
'''
    findedGroups = FindGroups(text)

    for group in findedGroups:
        print(group)






























