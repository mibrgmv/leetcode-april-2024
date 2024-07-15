class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int k = 0;
        while (!sandwiches.empty() && k < students.size()) {
            if (students.front() != sandwiches.front()) {
                students.push_back(students.front());
                students.erase(students.begin());
                ++k;
            } else {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                k=0;
            }
        }
        return students.size();
    }
};