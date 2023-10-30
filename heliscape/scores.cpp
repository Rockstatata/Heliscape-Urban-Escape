#include "scores.h"

template<> void scores<std::string,int>::setPlayername(const std::string &newPlayername)
{
    playername = newPlayername;
}

template<> void scores<std::string,int>::setScore(int newScore)
{
    score = newScore;
}

template<> std::string scores<std::string,int>::getPlayername() const
{
    return playername;
}

template<> scores<std::string,int>::scores():
    playername{""},score{0}
{

}

template<> scores<std::string,int>::scores(std::string p, int a):
    playername{p},score{a}
{

}

template<> void scores<std::string,int>::score_setter(std::string s, int p)
{
    playername = s;
    score = p;
}

template<> int scores<std::string,int>::getScore() const
{
    return score;
}

template<> void scores<std::string,int>::operator=(const scores<std::string,int> &s)
{
    this->playername = s.getPlayername();
    this->score = s.getScore();
}

std::ostream& operator<<(std::ostream &op,scores<std::string,int>& s){
    op<<s.getPlayername()<<" "<<s.getScore()<<"   "<<std::endl;
    return op;
}

std::istream& operator>>(std::istream &in,scores<std::string,int> &s){
    std::string p;int sc;
    in>>p>>sc;
    s.setPlayername(p);
    s.setScore(sc);
    return in;
}


