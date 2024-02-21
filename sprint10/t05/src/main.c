#include "../inc/header.h"

int compare_agents(const t_agent *a, const t_agent *b, int flag) {
    switch (flag) {
    case 1: 
        return a->power - b->power;
    case 2:
        return a->strength - b->strength;
    case 3:
        return mx_strcmp(a->name, b->name);
    default:
        return 0;
    }
}

void bubble_sort_agents(t_agent **agents, int count, int flag) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare_agents(agents[j], agents[j + 1], flag) > 0) {
                t_agent *temp = agents[j];
                agents[j] = agents[j + 1];
                agents[j + 1] = temp;
            }
        }
    }
}

void print_agents(t_agent **agents, int count) {
    for (int i = 0; i < count; i++) {
        mx_printstr("agent: ");
        mx_printstr(agents[i]->name);
        mx_printstr(", strength: ");
        mx_printint(agents[i]->strength);
        mx_printstr(", power: ");
        mx_printint(agents[i]->power);
        mx_printchar('$');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        return 1;
    }

    char *filename = argv[2];
    char *flag = argv[1];
    int flag_value = 0;

    if (mx_strcmp(flag, "-p") == 0) {
        flag_value = 1;
    } else if (mx_strcmp(flag, "-s") == 0) {
        flag_value = 2;
    } else if (mx_strcmp(flag, "-n") == 0) {
        flag_value = 3;
    } else {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        mx_printerr("error\n");
        return 1;
    }

    char *file_content = mx_file_to_str(filename);

    if (file_content == NULL) {
        mx_printerr("error\n");
        return 1;
    }

    t_agent *agents[MAX_AGENT_COUNT];
    int agent_count = 0;
    int index = 0;
    int agent_start = 0;
    char name[100];

    while (file_content[index] != '\0') {
        if (mx_strncmp(&file_content[index], " agent: ", 8) == 0) {
            agent_start = index + 8;
            index += 8;
            while (file_content[index] != ',' && file_content[index] != '\0') {
                index++;
            }

            mx_strncpy(name, &file_content[agent_start], index - agent_start);
            name[index - agent_start] = '\0';

            int strength, power;
            // Find strength
            while (file_content[index] != ':' && file_content[index] != '\0') {
                index++;
            }
            index++;
            while (!mx_isdigit(file_content[index]) && file_content[index] != '\0') {
                index++;
            }
            strength = mx_atoi(&file_content[index]);

            // Find power
            while (file_content[index] != ',' && file_content[index] != '\0') {
                index++;
            }
            index++;
            while (!mx_isdigit(file_content[index]) && file_content[index] != '\0') {
                index++;
            }
            power = mx_atoi(&file_content[index]);

            agents[agent_count] = mx_create_agent(name, power, strength);
            agent_count++;
        } else {
            mx_printerr("error\n");
            return 1;
        }

        while (file_content[index] != '$' && file_content[index] != '\0') {
            index++;
        }
        if (file_content[index] == '$') {
            index++;
        }
    }
    bubble_sort_agents(agents, agent_count, flag_value);
    print_agents(agents, agent_count);
    for (int i = 0; i < agent_count; i++) {
        free(agents[i]->name);
        free(agents[i]);
    }

    return 0;
}
