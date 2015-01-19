#ifndef CONTRIBUTORY_H
#define CONTRIBUTORY_H
#include "models/project.h"
#include "models/idatabasemodel.h"

/**
 * @author
 * @brief The Contributory class
 */
class Contributory : IDatabaseModel
{
public:
    Contributory();
    void commit();
    void hydrat(int getId);
    void remove();

    Project getProject() const;
    void setProject(const Project &value);

private:
    Project project;
};

#endif // CONTRIBUTORY_H
