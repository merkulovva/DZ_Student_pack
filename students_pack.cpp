#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

class Student {
private:
    vector<int> marks;
    string name;

public:
    Student(string n): name(n) {};

    bool operator == (const Student &other) const {
        return (name == other.name);
    }

    vector<int> getMarks() {
        return marks;
    }

    string getName() {
        return name;
    }

    // Метод для добавления отметки
    void addMark(int mark) {
        marks.push_back(mark);
    }

    void printMarks() {
        for (int i = 0; i < marks.size(); i++) {
            cout << marks[i] << ", ";
        }
        cout << endl;
    }

    // Метод для вычисления РАУ
    double calculateRAU() const {
        if (marks.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (int mark : marks) {
            sum += mark;
        }

        return sum / marks.size();
    }

    // Метод для определения является ли студент отличником
    bool isExcellentStudent() const {
        if (calculateRAU() >= 4.8) {
            cout << "Студент отличник" << endl;
            return 1;
        }
        else {
            cout << "Студент не отличник" << endl;
            return 0;
        }
    }

};


class Teacher {
protected:
    bool mood = rand() % 2;
    int moodCounter = 0;
    string name;

public:
    Teacher(string n): name(n) {};

    virtual string getName() {
        return name;
    }

    void setMood(bool m) {
        mood = m;
        if (mood == 0) cout << "Плохое настроение" << endl;
        else cout << "Хорошее настроение" << endl;
    }

    virtual void setMarkStudent(Student &student) {
        bool isExcellent = student.isExcellentStudent();

        if (mood == 1) {
            if (isExcellent) {
                student.addMark(5);
            }
            else {
                student.addMark(4);
            }
        }

        else {
            if (isExcellent) {
                student.addMark((rand() % 2 == 0) ? 4 : 5);
            }
            else {
                student.addMark((rand() % 2 == 0) ? 2 : 3);
            }
        }
        moodCounter++;
        if ((moodCounter % 5) == 0) {
            int moodChange = rand();
            setMood(moodChange % 2);
        }

    }

    void setMarkStudent(Student& student, int mark) {
        student.addMark(mark);
    }

};


class RandomMoodTeacher: public Teacher {
private:
    bool mood = rand() % 2;

public:
     RandomMoodTeacher(string n): Teacher(n) {};

     string getName() override {
        return name;
    }

    void setMarkStudent(Student &student) override {
        bool isExcellent = student.isExcellentStudent();

        if (mood == 1) {
            if (isExcellent) {
                student.addMark(5);
            }
            else {
                student.addMark(4);
            }
        }

        else {
            if (isExcellent) {
                student.addMark((rand() % 2 == 0) ? 4 : 5);
            }
            else {
                student.addMark((rand() % 2 == 0) ? 2 : 3);
            }
        }
        moodCounter++;
        if ((moodCounter % 2) == 0) {
            int moodChange = rand();
            setMood(moodChange % 2);
        }
    }

};

class KindTeacher: public Teacher {
public:
     KindTeacher(string n): Teacher(n) {};

     string getName() override {
        return name;
    }

    void setMarkStudent(Student &student) override {
        student.addMark(5);
    }

};

class EvilTeacher: public Teacher {
public:
    EvilTeacher(string n): Teacher(n) {};

    string getName() override {
        return name;
    }

    void setMarkStudent(Student &student) override {
        student.addMark(2);
    }

};


class Lesson {
private:
    vector<Student> groupList;
    string name;
    string teacherName;

public:
    Lesson(string n): name(n) {};

    void addStudent(Student &student) {
        groupList.push_back(student);
    }

    vector<Student> getAllStudents(){
        return groupList;
    }

    void setAllMarks(Teacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(KindTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(EvilTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(RandomMoodTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void printNewMarks() {
        int n = 0;
        for (int i = 0; i < groupList.size(); i++) {
            n++;
            cout << n << " студент: ";
            groupList[i].printMarks();
        }
        cout << endl;
    }

    Student getStudent(int num) {
        return groupList[num];
    }

    bool CertainIsExcellentStudent(Student &student) {
        float sum;
        for (int i = 1; i < student.getMarks().size(); i++) {
            sum += student.getMarks()[i];
        }
            sum = (sum / ((student.getMarks().size()) - 1));

        if (sum == 5) return 1;
        return 0;
    }

    string getLessonName() {
        return name;
    }

    string getTeacherName() {
        return teacherName;
    }

};


class Parent {
private:
    bool isGranny = 0;

protected:
    bool mood = rand() % 2;
    vector<Student> children;
    set<string> childrenList;

public:
    string sayTheBest() {
        return "Самый лучший внук (или внучка)!";
    };

    bool checkGrannyStatus() {
        return isGranny;
    }

    virtual bool Bch() {
        return 0;
    }

    void addChild(Student &child) {
        children.push_back(child);
        childrenList.insert(child.getName());
    }

    set<string> getList() {
        return childrenList;
    }

    void sayAboutAllChild() {
        if (children.size() == 0) return;

        for (int i = 0; i < children.size(); i++) {
            if (children[i].isExcellentStudent() && mood == 1) cout << children[i].getName() << " учится на отлично, он молодец. ";
            if (children[i].isExcellentStudent() && mood == 0) cout << children[i].getName() << " отличник, но не помогает мне по дому. ";
            if (!(children[i].isExcellentStudent()) && mood == 1) cout << children[i].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует. ";
            if (!(children[i].isExcellentStudent()) && mood == 0) cout << children[i].getName() << " плохо учится и не помогает по дому, он бесполезен.";
        }
        cout << endl;
    }

    void sayAboutRandomChild() {
        int n = rand() % children.size();

        if (children[n].isExcellentStudent() && mood == 1) cout << children[n].getName() << " учится на отлично, он молодец. ";
        if (children[n].isExcellentStudent() && mood == 0) cout << children[n].getName() << " отличник, но не помогает мне по дому. ";
        if (!(children[n].isExcellentStudent()) && mood == 1) cout << children[n].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует. ";
        if (!(children[n].isExcellentStudent()) && mood == 0) cout << children[n].getName() << " плохо учится и не помогает по дому, он бесполезен.";
        cout << endl;
    }

    void sayAboutGeneral () {
        bool token = 1;

        for (int i = 0; i < children.size(); i++) {
            if (children[i].isExcellentStudent()) continue;
            else token = 0;
        }
        if (token == 1 && mood == 1) cout << "Они самые лучшие дети" << endl;
        if (token == 1 && mood == 0) cout << "Они хорошие дети" << endl;
        if (token == 0 && mood == 1) cout << "Они хорошие дети, но не самые лучшие" << endl;
        if (token == 0 && mood == 0) cout << "Им стоит стараться лучше вести себя" << endl;
    }

    void sayAboutCertainChild(string name) {
        int counter = -1;

        for (int i = 0; i < children.size(); i++) {
            if ((children[i].getName()) == name) counter = i;
            else continue;
        }

        if (counter != -1) {
            bool token = 1;

            for (int i = 0; i < children.size(); i++) {
                if (!children[i].isExcellentStudent()) token = 0;
            }
            if (token == 1 && mood == 1) cout << children[counter].getName() << " учится на отлично, он молодец." << endl;
            if (token == 1 && mood == 0) cout << children[counter].getName() << " отличник, но не помогает мне по дому." << endl;
            if (token == 0 && mood == 1) cout << children[counter].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует." << endl;
            if (token == 0 && mood == 0) cout << children[counter].getName() << " плохо учится и не помогает по дому, он бесполезен." << endl;
        }
        else cout << name << " - это не мой ребенок" << endl;
    }

    vector<Student> getChildren() {
        return children;
    }

};

class Granny: public Parent {
private:
    bool isGranny = 1;

public:
    bool Bch() override {
        return 1;
    }
};


class Meeting {
private:
    set<string> list_1;
    set<string> list_2;

    vector<Parent*> parents;
    vector<Teacher> teachers;
    vector<Lesson> lessons;

public:
    Meeting() {
        cout << "Новое собрание!" << endl;
    }

    void showList_1() {
        if (list_2.size() == 0) {
            cout << endl;
            return;
        }
        cout << "Список студентов, родители которых не пришли на Собрание: ";
        for (const auto& elem : list_2) {
            cout << elem << "  ";
        }
        cout << endl;
    }

    void addParent(Parent *parent) {
        parents.push_back(parent);
    }

    void addParent(Granny *granny) {
        parents.push_back(granny);
    }

    void addTeacher(Teacher &teacher) {
        teachers.push_back(teacher);
    }

    void addLesson(Lesson &lesson) {
        lessons.push_back(lesson);
    }

    void talkAbout() {
        for (int i = 0; i < lessons.size(); i++) {
            for (int check = 0; check < teachers.size(); check++) {
                if (teachers[check].getName() == lessons[i].getTeacherName()) goto metka;
            }

            cout << lessons[i].getLessonName() << " Занятие: ";
            cout << "Учителя нет" << endl;
            return;
            /////////////////////
            metka:
            cout << lessons[i].getLessonName() << " Занятие: " << endl;

            for (int j = 0; j < parents.size(); j++) {
                cout << "Родитель " << (j+1) << ": ";

                for (int k = 0; k < parents[j]->getChildren().size(); k++) {
                    for (int n = 0; n < (lessons[i].getAllStudents()).size(); n++) {

                            if ((lessons[i].getAllStudents())[n].getName() == parents[j]->getChildren()[k].getName())
                            {
                                Student temp = (parents[j]->getChildren()[k]);
                                if (lessons[i].CertainIsExcellentStudent(lessons[i].getAllStudents()[n])) {
                                    if (parents[j]->Bch()) (cout << temp.getName() << " " << parents[j]->sayTheBest());
                                    else cout << temp.getName() << " хорошо учится. ";
                                }

                                else {
                                    if (parents[j]->Bch()) (cout << temp.getName() << " " << parents[j]->sayTheBest());
                                    else cout << temp.getName() << " очень старается. ";
                                }
                            }
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        for (int i = 0; i < lessons.size(); i++) {
            for (int j = 0; j < parents.size(); j++) {

                   for (int n = 0; n < (lessons[i].getAllStudents()).size(); n++) {
                        if ((parents[j]->getList().count(((lessons[i].getAllStudents())[n]).getName()))) list_1.insert(((lessons[i].getAllStudents())[n]).getName());
                   }
            }
        }

        for (int i = 0; i < lessons.size(); i++) {

            for (int j = 0; j < (lessons[i].getAllStudents().size()); j++) {
                if (!(list_1.count((lessons[i].getAllStudents())[j].getName()))) list_2.insert((lessons[i].getAllStudents())[j].getName());
            }
        }

    }

};



int main() {
    srand(time(NULL));

    Student a("Аня");
    Student b("Миша");
    Student c("Гриша");
    Student d("Юля");

    a.addMark(5);
    b.addMark(3);
    c.addMark(4);
    d.addMark(5);

    Parent p;
    p.addChild(a);
    p.addChild(b);
    p.addChild(c);
    p.addChild(d);

    Teacher t1("art");
    Teacher t2("math");

    Parent p1;
    p1.addChild(a);
    p1.addChild(b);
    p1.addChild(c);
    p1.addChild(d);

    Parent p2;
    Student e("Ваня");
    e.addMark(5);
    p2.addChild(e);

    Granny p3;
    Student f("Маша");
    f.addMark(4);

    p3.addChild(f);
    Lesson art("art");

    art.addStudent(a);
    art.addStudent(c);
    art.addStudent(e);
    art.addStudent(f);

    art.setAllMarks(t1);
    art.setAllMarks(t1);
    art.setAllMarks(t1);
    Lesson mat("math");

    mat.addStudent(b);
    mat.addStudent(e);
    mat.addStudent(d);
    mat.addStudent(f);
    mat.setAllMarks(t2);
    mat.setAllMarks(t2);

    Meeting m1;
    m1.addTeacher(t1);
    m1.addParent(&p1);
    m1.addParent(&p2);
    m1.addParent(&p3);

    m1.addLesson(art);
    m1.addLesson(mat);
    m1.talkAbout();
    m1.showList_1();

    Meeting m2;
    m2.addTeacher(t2);
    m2.addParent(&p1);
    m2.addParent(&p2);
    m2.addParent(&p3);
    m2.addLesson(mat);
    m2.talkAbout();
    m2.showList_1();

    return 0;
}
