#include <iostream>
using namespace std;

struct peak
{
    string name;
    unsigned int height;
};

void sort(peak *peaks, int number_of_begin, int number_of_end)
{
    // sortowanie przez wstawianie
    int j;
    peak key;
    for (int i = number_of_begin + 1; i < number_of_end; i++)
    {
        key = peaks[i];
        j = i - 1;
        while (j >= number_of_begin && peaks[j].height > key.height)
        {
            peaks[j + 1] = peaks[j];
            j--;
        }
        peaks[j + 1] = key;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int number_of_tests, number_of_peaks;
    cin >> number_of_tests;

    for (int i = 0; i < number_of_tests; i++)
    {
        cin >> number_of_peaks;
        peak *peaks = new peak[number_of_peaks];

        int power_counter = 0;

        for (int j = 0; j < number_of_peaks; j++)
        {
            cin >> peaks[j].name >> peaks[j].height;
            if (!(peaks[j].height == 0) && !(peaks[j].height & (peaks[j].height - 1)))
            {
                power_counter++;
            }
        }

        peak *power_peaks = new peak[power_counter];
        peak *not_power_peaks = new peak[number_of_peaks - power_counter];

        for (int j = 0, k = 0, l = 0; j < number_of_peaks; j++)
        {
            if (!(peaks[j].height == 0) && !(peaks[j].height & (peaks[j].height - 1)))
            {
                power_peaks[k] = peaks[j];
                k++;
            }
            else
            {
                not_power_peaks[l] = peaks[j];
                l++;
            }
        }

        sort(power_peaks, 0, power_counter);
        sort(not_power_peaks, 0, number_of_peaks - power_counter);

        for (int j = 0; j < power_counter; j++)
        {
            cout << power_peaks[j].name << "-" << power_peaks[j].height << " ";
        }
        for (int j = 0; j < number_of_peaks - power_counter; j++)
        {
            cout << not_power_peaks[j].name << "-" << not_power_peaks[j].height << " ";
        }
        cout << endl;

        delete[] peaks;
        delete[] power_peaks;
        delete[] not_power_peaks;
    }

    return 0;
}