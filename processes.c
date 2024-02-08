
#include "processes.h"

struct Process processes[5];
int processescount = 0;

static int nextid = 1;

int nextprocessid() {
    if (nextid <= 5) {
        return nextid++;
    } else {
        return 0; 
    }
}

int createnewprocess(const char *name) {
    if (processescount < 5) {
        int id = nextprocessid();
        if (id != 0) {
            processes[processescount].id = id;
            snprintf(processes[processescount].name, sizeof(processes[processescount].name), "%s", name);
            processescount++;
        }
        return id;
    } else {
        return 0; 
    }
}

void stopprocess(int processid) {
    if (processid >= 1 && processid <= nextid) {
        for (int i = 0; i < processescount; ++i) {
            if (processes[i].id == processid) {
                for (int j = i; j < processescount - 1; ++j) {
                    processes[j] = processes[j + 1];
                }
                processescount--;
                break;
            }
        }
    }
}
