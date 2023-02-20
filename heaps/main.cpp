#include <iostream>
using namespace std;

struct tower
{
    int priorytet;
    int value;
    int index;
};

void resize(tower *&arr, int newSize)
{
    tower *temp = new tower[newSize];
    for (int i = 0; i < newSize / 2; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void swap_elements(tower heap1[], tower heap2[], int i, int j)
{
    swap(heap2[heap1[i].index].index, heap2[heap1[j].index].index); // zamieniamy indeksy w drugim kopcu
    swap(heap1[i], heap1[j]);                                       // zamieniamy elementy w pierwszym kopcu
}

void heapify_up_max(tower arr[], int i, tower min[])
{
    int parent = (i - 1) / 2;

    if (arr[parent].priorytet < arr[i].priorytet)
    {
        swap_elements(arr, min, parent, i);

        heapify_up_max(arr, parent, min);
    }
}

void heapify_up_min(tower arr[], int i, tower max[])
{
    int parent = (i - 1) / 2;

    if (arr[parent].priorytet > arr[i].priorytet)
    {
        swap_elements(arr, max, parent, i);
        heapify_up_min(arr, parent, max);
    }
}

void heapify_down_max(tower arr[], int n, int i, tower min[])
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].priorytet > arr[largest].priorytet) // jeśli lewy syn ma większy priorytet to zapisujemy jego indeks oraz czy lewsy syn jest mniejszy od rozmiaru kopca
        largest = left;

    if (right < n && arr[right].priorytet > arr[largest].priorytet)
        largest = right;

    if (largest != i)
    {
        swap_elements(arr, min, i, largest);
        heapify_down_max(arr, n, largest, min);
    }
}

void heapify_down_min(tower arr[], int n, int i, tower max[])
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].priorytet < arr[largest].priorytet)
        largest = left;

    if (right < n && arr[right].priorytet < arr[largest].priorytet)
        largest = right;

    if (largest != i)
    {
        swap_elements(arr, max, i, largest);
        heapify_down_min(arr, n, largest, max);
    }
}

void delete_max(tower min[], tower max[], int &n) // usuwa maksymalny element z kopca max i aktualizuje kopiec min
{
    int temp = max[0].index;           // zapisujemy indeks elementu który chcemy usunąć
    swap_elements(max, min, 0, n - 1); // zamieniamy korzeń z ostatnim elementem

    int i = max[n - 1].index; // zapisujemy indeks elementu który zamieniliśmy z korzeniem

    swap_elements(min, max, i, n - 1); // zamieniamy elementy w drugim kopcu aby zachować spójność

    n--;

    heapify_down_max(max, n, 0, min);
    heapify_up_min(min, temp, max);
}

void delete_min(tower min[], tower max[], int &n)
{
    int temp = min[0].index;

    swap_elements(min, max, 0, n - 1);

    int i = min[n - 1].index;

    swap_elements(max, min, i, n - 1);

    n--;

    heapify_down_min(min, n, 0, max);

    heapify_up_max(max, temp, min);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;         // liczba zestawów
    int m;         // dane pojedynczego zestawu
    int operation; // operacja 0 - operacja dodania zgłoszenia a o priorytecie
    // b, 1- naprawa wieży o najwyższym priorytecie - usuwamy,
    // 2- rezygnacja z naprawy o najmniejszym priorytecie -
    // usuwamy
    cin >> n;

    int maxSize = 16;
    tower *max = new tower[maxSize];
    tower *min = new tower[maxSize];

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        int size = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> operation;

            switch (operation)
            {
            case 0:
            {
                // dodanie wieży do kopców czyli korzystamy z heapifyUp
                int a, b;
                cin >> a >> b;
                tower t;
                t.priorytet = b;
                t.value = a;
                t.index = size;

                if (maxSize < size + 1) // sprawdzamy czy tablica jest za mała
                {
                    resize(max, maxSize * 2);
                    resize(min, maxSize * 2);
                    maxSize *= 2;
                }
                max[size] = t;
                min[size] = t;

                heapify_up_max(max, size, min);
                heapify_up_min(min, size, max);
                size++;

                break;
            }
            case 1:
            {
                // naprawa wieży o najwyższym priorytecie  usuwamy
                // korzeń z kopca max ale też musimy usunąć z kopca min
                if (size > 0)
                {
                    cout << max[0].value << '\n';
                    delete_max(min, max, size);
                }
                break;
            }
            case 2:
            {
                if (size > 0)
                {
                    cout << min[0].value << '\n';
                    delete_min(min, max, size);
                }
                break;
            }
            }
        }
    }
    delete[] max;
    delete[] min;

    return 0;
}