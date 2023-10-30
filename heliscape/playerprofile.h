#ifndef PLAYERPROFILE_H
#define PLAYERPROFILE_H

// The player profile class which stores data of the players
// Aggregation with Score Class
#include "scores.h"

class playerprofile
{
private:
    std::string playername;
    std::vector<scores<std::string,int>>sessionscores;
public:
    playerprofile();
    playerprofile(std::string name,std::vector<scores<std::string,int>>scores);
    std::vector<scores<std::string,int>>& getSessionscores();
    std::string getPlayername();
    void setPlayername(const std::string &newPlayername);
};

#endif // PLAYERPROFILE_H
