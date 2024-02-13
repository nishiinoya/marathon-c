#include "only_smiths.h"

t_agent **mx_only_smiths(t_agent **agents, int strength) {
    if (!agents)
        return NULL;

    int count = 0;
    for (int i = 0; agents[i] != NULL; i++) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength)
            count++;
    }

    t_agent **only_smiths = (t_agent **)malloc((count + 1) * sizeof(t_agent *));
    if (!only_smiths)
        return NULL;

    for (int i = 0, j = 0; agents[i] != NULL; i++) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength) {
            only_smiths[j] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
            j++;
        }
    }

    only_smiths[count] = NULL;
    mx_exterminate_agents(&agents);

    return only_smiths;
}
