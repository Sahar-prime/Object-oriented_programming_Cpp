#pragma once
class Task
{
    char title[50];
    char description[150];
    bool status;
public:
    Task();
    Task(const char* newTitle, const char* newDescription, bool newStatus);
    Task(const Task& other);
    ~Task();

    void input();
    void print();
    
    Task& setTitle(const char* title);
    Task& setDescription(const char* description);
    Task& setStatus(bool status);

    const char* getTitle() const;
    const char* getDescription() const;
    bool getStatus() const;
};

