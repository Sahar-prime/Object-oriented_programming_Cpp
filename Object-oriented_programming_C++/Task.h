#pragma once
class Task
{
    char title[50];
    char description[150];
    bool status;
public:
    void input();
    void print();
    
    void setTitle(const char* newTitle);
    void setDescription(const char* newDescription);
    void setStatus(bool newStatus);

    const char* getTitle() const;
    const char* getDescription() const;
    bool getStatus() const;
};

