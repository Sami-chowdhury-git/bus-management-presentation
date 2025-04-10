#include<bits/stdc++.h>
using namespace std;
struct Activity
{string name;
float start_time, end_time;
};
bool comp(Activity act1, Activity act2)
{
return (act1.end_time<act2.end_time);
}
int main()
{
int n;
printf("Enter the number of activity: ");
cin >> n;
Activity arr[n];
for(int i=0; i<n; i++)
{
cin >> arr[i].name >> arr[i].start_time >> arr[i].end_time;
}
sort(arr, arr+n, comp);
int j = 0, count =1;
for (int i = 1; i < n; i++)
{
if (arr[i].start_time >= arr[j].end_time)
{
count++;
j = i;
}
}
cout << "Maximum selected activity: " << count << endl;
}
