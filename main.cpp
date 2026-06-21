#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
};

vector<Student> students;

// 功能1：新增學生
void addStudent() {
    Student s;
    cout << "輸入學號 姓名 成績：";
    cin >> s.id >> s.name >> s.score;

    // 檢查是否重複
    for (auto &st : students) {
        if (st.id == s.id) {
            cout << "學號已存在，拒絕新增！\n";
            return;
        }
    }

    students.push_back(s);
    cout << "新增成功！\n";
}

// 功能2：列出所有學生
void listStudents() {
    if (students.empty()) {
        cout << "沒有資料\n";
        return;
    }

    cout << "學號\t姓名\t成績\n";
    for (auto &s : students) {
        cout << s.id << "\t" << s.name << "\t" << s.score << endl;
    }
}

// 功能3：依成績排序
void sortStudents() 
{
    sort(students.begin(), students.end(),[](const Student &a, const Student &b) {return a.score > b.score;});

    cout << "已依成績排序\n";
}

// 功能4：查詢學生
void searchStudent() {
    string id;
    cout << "輸入學號：";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "找到："
                 << s.id << " "
                 << s.name << " "
                 << s.score << endl;
            return;
        }
    }

    cout << "查無此人\n";
}

// 功能5：統計成績
void statistics() {
    if (students.empty()) {
        cout << "沒有資料\n";
        return;
    }

    int sum = 0;
    int maxScore = students[0].score;
    int minScore = students[0].score;
    int pass = 0, fail = 0;

    for (auto &s : students) {
        sum += s.score;

        if (s.score > maxScore) maxScore = s.score;
        if (s.score < minScore) minScore = s.score;

        if (s.score >= 60) pass++;
        else fail++;
    }

    cout << "平均: " << (double)sum / students.size() << endl;
    cout << "最高: " << maxScore << endl;
    cout << "最低: " << minScore << endl;
    cout << "及格: " << pass << endl;
    cout << "不及格: " << fail << endl;
}

// 主程式（選單）
int main() {
    int choice;

    do {
        cout << "\n1. Add student\n";
        cout << "2. List all students\n";
        cout << "3. Sort by score\n";
        cout << "4. Search by id\n";
        cout << "5. Show statistics\n";
        cout << "0. Exit\n";
        cout << "選擇：";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: sortStudents(); break;
            case 4: searchStudent(); break;
            case 5: statistics(); break;
        }

    } while (choice != 0);

    return 0;
}