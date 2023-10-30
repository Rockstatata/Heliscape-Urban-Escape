#ifndef SCORES_H
#define SCORES_H

// Template Class

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

template<class U,class V>
class scores
{
private:
    U playername;
    V score;

public:
    scores();
    scores(U, V);
    int scoregetter();
    int getScore() const;

    void operator=(const scores &s);
    friend std::ostream& operator<<(std::ostream &op,scores<U,V>& s);
    friend std::istream& operator>>(std::istream &op,scores<U,V>& s);

    void setPlayername(const std::string &newPlayername);
    void setScore(int newScore);
    std::string getPlayername() const;
    void score_setter(std::string s, int p);
};

#endif // SCORES_H
