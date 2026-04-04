#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
   
    int serja_score = 0;
    int dhima_score = 0;

    int i = 0, j = n - 1;
    bool serja_turn = true;

    while (i <= j)
    {
        // serja move first
        if (serja_turn)
        {
            if (array[i] >= array[j])
            {
                serja_score += array[i];
                i++;
            }
            else
            {
                serja_score += array[j];
                j--;
            }
            serja_turn = false;
        }

        // then dhima's turn
        else
        {
            if (array[i] >= array[j])
            {
                dhima_score += array[i];
                i++;
            }
            else
            {
                dhima_score += array[j];
                j--;
            }
             serja_turn = true;
        }
    }

    cout << serja_score << " " << dhima_score << endl;

    return 0;
}