#include "playerprofile.h"

void playerprofile::setPlayername(const std::string &newPlayername)
{
    playername = newPlayername;
}

playerprofile::playerprofile()
{
    playername="";
}

playerprofile::playerprofile(std::string name, std::vector<scores<std::string,int>> score)
{
    playername = name;
    sessionscores = score;
}

std::string playerprofile::getPlayername()
{
    return playername;
}

std::vector<scores<std::string,int>>& playerprofile::getSessionscores()
{
    return sessionscores;
}
