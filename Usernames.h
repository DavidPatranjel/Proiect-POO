//
// Created by David on 25/04/2022.
//

#ifndef OOP_USERNAMES_H
#define OOP_USERNAMES_H


class Usernames{
    std::vector<std::string> usernames;
public:
    ///Getter - usernames
    const std::vector<std::string> &getUsernames() const;

    ///Setter - usernames
    void setUsernames(const std::vector<std::string> &usernames_);
};


#endif //OOP_USERNAMES_H
