#include <iostream>
#include <string>
using namespace std;

struct person
{
    string name;
    int amount_of_skills;
    double height;
    int avg_speed;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        int first, second, third;
        cin >> m;
        cin >> first >> second >> third;

        person MAXresident; // najlepszy mieszkaniec
        person resident;    // aktualnie sprawdzany mieszkaniec

        cin >> MAXresident.name >> MAXresident.amount_of_skills >> MAXresident.height >> MAXresident.avg_speed;

        for (int i = 1; i < m; i++)
        {
            cin >> resident.name >> resident.amount_of_skills >> resident.height >> resident.avg_speed;
            switch (first)
            {
            case 1:
                if (resident.amount_of_skills > MAXresident.amount_of_skills)
                {
                    MAXresident = resident;
                }
                else if (resident.amount_of_skills == MAXresident.amount_of_skills)
                {
                    switch (second)
                    {
                    case 2:
                        if (resident.height > MAXresident.height)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.height == MAXresident.height)
                        {
                            switch (third)
                            {
                            case 3:
                                if (resident.avg_speed > MAXresident.avg_speed)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    case 3:
                        if (resident.avg_speed > MAXresident.avg_speed)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.avg_speed == MAXresident.avg_speed)
                        {
                            switch (third)
                            {
                            case 2:
                                if (resident.height > MAXresident.height)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 2:
                if (resident.height > MAXresident.height)
                {
                    MAXresident = resident;
                }
                else if (resident.height == MAXresident.height)
                {
                    switch (second)
                    {
                    case 1:
                        if (resident.amount_of_skills > MAXresident.amount_of_skills)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.amount_of_skills == MAXresident.amount_of_skills)
                        {
                            switch (third)
                            {
                            case 3:
                                if (resident.avg_speed > MAXresident.avg_speed)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    case 3:
                        if (resident.avg_speed > MAXresident.avg_speed)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.avg_speed == MAXresident.avg_speed)
                        {
                            switch (third)
                            {
                            case 1:
                                if (resident.amount_of_skills > MAXresident.amount_of_skills)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 3:
                if (resident.avg_speed > MAXresident.avg_speed)
                {
                    MAXresident = resident;
                }
                else if (resident.avg_speed == MAXresident.avg_speed)
                {
                    switch (second)
                    {
                    case 1:
                        if (resident.amount_of_skills > MAXresident.amount_of_skills)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.amount_of_skills == MAXresident.amount_of_skills)
                        {
                            switch (third)
                            {
                            case 2:
                                if (resident.height > MAXresident.height)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    case 2:
                        if (resident.height > MAXresident.height)
                        {
                            MAXresident = resident;
                        }
                        else if (resident.height == MAXresident.height)
                        {
                            switch (third)
                            {
                            case 1:
                                if (resident.amount_of_skills > MAXresident.amount_of_skills)
                                {
                                    MAXresident = resident;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            default:
                break;
            }
        }
        cout << MAXresident.name << endl;
    }

    return 0;
}