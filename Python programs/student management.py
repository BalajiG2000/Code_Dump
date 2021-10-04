import os
import json
import sys
print(os.getcwd())
try:
    os.mkdir('project')
except FileExistsError:
    pass
os.chdir('project')

#passwords
st_pwd='password'
te_pwd='password'
ad_pwd='password'

def new_student():
    try:
        print('*'*15)
        student_info=open('student.txt','a')
        print('-'*10)
        st_di={'Id':int(input('enter the student id:-')),'name':input('enter the student name:-'),'Cls':int(input('enter the student class:-')),
           'phy':int(input('enter  the marks in physics:-')),'chem':int(input('enter the marks in chemistry:-')),
           'math':int(input('enter the marks in math:-'))}
        print('-'*10)
        student_info.write(json.dumps(st_di))
        student_info.write('\n')
        print('student added successfully')
    except :
        print('something went wrong')
    finally:
        student_info.close()

def stud_details():
    try:
        print('*'*15)
        student_info=open("student.txt","r")
        print(student_info.read())
    except FileNotFoundError:
        print('no students')
    except:
        print('something went wrong')
    finally:
        student_info.close()

def stud_search():
    try:
        print('*'*15)
        student_info=open('student.txt','r')
        Id=int(input('enter the id of student to search:-'))
        flag=0
        for s in student_info.readlines():
            li=json.loads(s)
            if(li['Id']==Id):
                flag=1
                print(li)
        if(flag==0):
            print('not found')
    except FileNotFoundError:
        print('no students')
    except:
        print('something went wrong')
    finally:
        student_info.close()

def stud_update():
    try:
        print('*'*15)
        stud_r=open("student.txt",'r')
        flag=0
        li=[]
        for s in stud_r.readlines():
            li.append(json.loads(s))
        stud_r.close()
        stud_w=open("student.txt",'w')
        Id=int(input('enter the student id:-'))
        for i in li:
            #print(type(i))
            #print(type(i['Id']))
            if(i['Id']==Id):
                flag=1
                print(s)
                while(True):
                    print('1:-update in physics\n2:-update in chem\n3:-update in math\nanykey:-complete update')
                    choice=input('enter the choice')
                    if choice=='1':
                        mark=int(input('enteer the physics mark:-'))
                        i['phy']=mark
                    elif choice=='2':
                        mark=int(input('enteer the chem mark:-'))
                        i['chem']=mark
                    elif choice=='3':
                        mark=int(input('enteer the math mark:-'))
                        i['math']=mark
                    else:
                        print('update done see',i)
                        stud_w.write(json.dumps(i))
                        stud_w.write('\n')
                        break
            else:
                stud_w.write(json.dumps(i))
                stud_w.write('\n')
        if(flag==0):
            print('not found')
    except FileNotFoundError:
        print('no students')
    except:
        print('something went wrong')
    finally:
        stud_w.close()


def stud_remove():
    try:
        print('*'*15)
        stud_r=open("student.txt",'r')
        flag=0
        li=[]
        for s in stud_r.readlines():
            li.append(json.loads(s))
        stud_r.close()
        stud_w=open("student.txt",'w')
        Id=int(input('enter the student id:-'))
        for i in li:
            if(i['Id']!=Id):
                stud_w.write(json.dumps(i))
                stud_w.write('\n')
            else:
                flag=1
                print('student',i,'removed succesfully')
        if(flag==0):
            print('not present')
    except FileNotFoundError:
        print('no students')
    except:
        print('something went wrong')
    finally:
        stud_w.close()


def new_teacher():
    try:
        print('*'*15)
        teacher_info=open('teacher.txt','a')
        te_di={'Id':int(input('enter the teacher id:-')),'name':input('enter the teacher name:-'),
        'sub':input('enter which subject he/she teach from phy/chem/math:-'),'Cls':int(input('enter which class he/she will teach:-'))}
        teacher_info.write(json.dumps(te_di))
        teacher_info.write('\n')
        print('teacher added successfully')
    except:
        print('something went wrong')
    finally:
        teacher_info.close()

def teach_details():
    try:
        print('*'*15)
        teacher_info=open("teacher.txt","r")
        print(teacher_info.read())
    except FileNotFoundError:
        print('no teacher')
    except:
        print('something went wrong')
    finally:
        teacher_info.close()

def teach_search():
    try:
        print('*'*15)
        teacher_info=open('teacher.txt','r')
        flag=0
        Id=int(input('enter the id of teacher to search:-'))
        for s in teacher_info.readlines():
            li=json.loads(s)
            if(li['Id']==Id):
                flag=1
                print(li)
        if(flag==0):
            print('not found')
    except FileNotFoundError:
        print('no teacher')
    except:
        print('something went wrong')
    finally:
        teacher_info.close()

def teach_remove():
    try:
        print('*'*15)
        teach_r=open("teacher.txt",'r')
        flag=0
        li=[]
        for s in teach_r.readlines():
            li.append(json.loads(s))
        teach_r.close()
        teach_w=open("teacher.txt",'w')
        Id=int(input('enter the teacher id:-'))
        for i in li:
            if(i['Id']!=Id):
                teach_w.write(json.dumps(i))
                teach_w.write('\n')
            else:
                flag=1
                print('teacher',i,'removed successfully')
        if(flag==0):
            print('not present')
    except FileNotFoundError:
        print('no teacher')
    except:
        print('something went wrong')
    finally:
        teach_w.close()



def menu():
    while(True):
        print('*'*20)
        print('1:-Login as admin\n2:-Login as student\n3:-login as teacher\nq:-to quit')
        choice=input('enter ur choice:-')
        if choice=='1':
            Login('a')
        elif choice=='2':
            Login('s')
        elif choice=='3':
            Login('t')
        elif choice=='q':
            print('thank you')
            sys.exit()
        else:
            print('incorrect enter')
            print('plz enter again')


def Login(Type):
    if Type=='s':
        Login_stud()
    elif Type=='a':
        Login_adm()
    elif Type=='t':
        Login_teach()

def Login_stud():
    print('*'*10)
    user=input('enter the user name:-')
    stu_pwd=input('enter the password:-')
    if(user=='student' and stu_pwd==st_pwd):
        print('logged in successfully')
        print('welcome    ',user)
        while(True):
            print('*'*20)
            print('1:-student details\n2:-student search\n3:-teacher details\n4:-teacher search')
            print('5:-change password\nq:-to exit')
            choice=input('enter the choice:-')
            if choice=='1':
                stud_details()
            elif choice=='2':
                stud_search()
            elif choice=='3':
                teach_details()
            elif choice=='4':
                teach_search()
            elif choice=='5':
                ch_pwd()
            elif choice=='q':
                print('logged out successfully')
                break
            else:
                pass

def Login_teach():
    print('*'*10)
    user=input('enter the user name:-')
    tea_pwd=input('enter the password:-')
    if(user=='teacher' and tea_pwd==te_pwd):
        print('logged in successfully')
        print('welcome    ',user)
        while(True):
            print('*'*20)
            print('1:-student details\n2:-student search\3:-stud_update')
            print('4:-teacher details\n5:-teacher search\n6:-change password\nq:-to exit')
            choice=input('enter the choice:-')
            if choice=='1':
                stud_details()
            elif choice=='2':
                stud_search()
            elif choice=='3':
                stud_update()
            elif choice=='4':
                teach_details()
            elif choice=='5':
                teach_search()
            elif choice=='6':
                ch_pwd('t')
            elif choice=='q':
                print('logged out successfully')
                break
            else:
                pass
                
def Login_adm():
    print('*'*10)
    user=input('enter the user name:-')
    adm_pwd=input('enter the password:-')
    if(user=='admin' and adm_pwd==ad_pwd):
        print('logged in successfully')
        print('welcome    ',user)
        while(True):
            print('*'*20)
            print('1:-add student\n2:-student details\n3:-remove student\n4:-add teacher')
            print('5:-teacher details\n6:-removal teacher\n7:-change password\nq:-to exit')
            choice=input('enter the choice:-')
            if choice=='1':
                new_student()
            if choice=='2':
                stud_details()
            elif choice=='3':
                stud_remove()
            elif choice=='4':
                new_teacher()
            elif choice=='5':
                teach_details()
            elif choice=='6':
                teach_remove()
            elif choice=='7':
                ch_pwd('a')
            elif choice=='q':
                print('logged out successfully')
                break
            else:
                pass



def ch_pwd(Type):
    while(True):
        print('*'*20)
        pwd=input('enter ur new password:-')
        l=0;u=0;d=0;s=0
        if(len(pwd)>=8 and len(pwd)<=20):
            for i in pwd:
                if(i.islower()):
                    l+=1
                elif(i.isupper()):
                    u+=1
                elif(i.isdigit()):
                    d+=1
                elif(i=='!' or i=='@' or i=='#' or i=='$' or i=='%' or i=='&'):
                    s+=1
            if(l>=1 and u>=1 and d>=1 and s>=1 and l+u+d+s==len(pwd)):
                print('valid password')
                print('password changed successfully')
                if (Type=='s'):
                    global st_pwd
                    st_pwd=pwd
                    try:
                        fi=open('student_password.txt','w')
                        fi.write(st_pwd+'\n')
                    except:
                        print('something error')
                    finally:
                        fi.close()
                elif(Type=='t'):
                    global te_pwd
                    te_pwd=pwd
                    try:
                        fi=open('teacher_password.txt','w')
                        fi.write(te_pwd+'\n')
                    except:
                        print('something error')
                    finally:
                        fi.close()
                elif(Type=='a'):
                    global ad_pwd
                    ad_pwd=pwd
                    try:
                        fi=open('admin_password.txt','w')
                        fi.write(ad_pwd+'\n')
                    except:
                        print('something error')
                    finally:
                        fi.close()

                return
            else:
                print('invalid password ,try again')
        else:
            print('length is not matched')

#student managent menu            
menu()
