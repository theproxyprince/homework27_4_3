#pragma once
#include "Worker.h"
#include <ctime>

class Manager {
private:
    int countWorkers = 1;
    Worker** workers = nullptr;
    int managerNumber;

public:
    Manager();
    ~Manager();
    static int gen;
    void SetCountWorkers(int inCountWorkers);
    int GetCountWorkers();
    Worker* GetWorkerPtr(int index);
    int GetTaskCount(int task);
    int GetFreeWorkers();
    std::string GetRandomTask();
    int SetTaskToWorkers(int task);
    int GetManagerNumber();
};

