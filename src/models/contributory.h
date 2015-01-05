#ifndef CONTRIBUTORY_H
#define CONTRIBUTORY_H
#include "models/project.h"

class Contributory
{
public:
    Contributory();

    Project getProject() const;
    void setProject(const Project &value);

private:
    Project project;
};

#endif // CONTRIBUTORY_H
