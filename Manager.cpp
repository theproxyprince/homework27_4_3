#include "Manager.h"

int Manager::gen;

Manager::Manager(){
    managerNumber = ++Manager::gen;
}

void Manager::SetCountWorkers(int inCountWorkers){
    if(inCountWorkers > 0) {
        countWorkers = inCountWorkers;
    } else {
        countWorkers = 1;
    }

    workers = new Worker*[countWorkers];

    for (int i =0; i < countWorkers; ++i) {
        workers[i] = new Worker(this);
    }
}

Manager::~Manager() {
    delete workers;
}
int Manager::GetCountWorkers(){return countWorkers;}
Worker* Manager::GetWorkerPtr(int index){return workers[index];}
int Manager::GetTaskCount(int task){
    std::srand(task + managerNumber);
    return std::rand() % countWorkers + 1;
}

int Manager::GetFreeWorkers(){
    int count = 0;
    for(int i = 0; i < countWorkers; ++i){
        if(workers[i]->GetTask() == "nothing") count++;
    }
    return count;
}

std::string Manager::GetRandomTask(){
    std::srand(time(nullptr));
    int task = rand() % 3;
    std::string str;

    switch(task) {
        case 0:
            break;

    }

    switch (task) {
        case 0:
            str = "task A";
            break;
        case 1:
            str = "task B";
            break;
        case 2:
            str = "task C";
            break;
        default:
            str = "nothing";
            break;
    }
    return  str;
}

int Manager::SetTaskToWorkers(int task) {
    int count = 0;
    std::srand(task + GetManagerNumber());
    int realTask = std::rand() % GetCountWorkers() + 1;
    if (realTask > 0 && GetFreeWorkers() > 0) {
        for (int i = 0; i < countWorkers; ++i) {
            if (workers[i]->GetTask() == "nothing") {

                workers[i]->SetTask(GetRandomTask());
                count++;
                realTask--;
                if (realTask == 0) {
                    break;
                }
            }
        }
    }
    return  count;
}

int Manager::GetManagerNumber(){
    return managerNumber;
}