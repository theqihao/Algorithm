/*#include <iostream>    // c++ 中的标准输入输出头文件，必须包含
#include <algorithm>   // algorithm,中文即为算法，包含了大量常用高效的算法函数
#include <cstdio>
using namespace std;   // 标准命名空间，缺省这个语句，sort 调用不了

int main()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};

	// 要求对 a 排序后输出

	sort(a,a+10);   // sort 传入的第一个参数，是数组名，即数组地址，第二个参数是数组要排序的长度

	for(int i=9;i>=0;i--)
		printf("%d\n",a[i]);
	return 0;
}


#include <iostream>    // c++ 中的标准输入输出头文件，必须包含
#include <algorithm>   // algorithm,中文即为算法，包含了大量常用高效的算法函数
#include <cstdio>

using namespace std;   // 标准命名空间，缺省这个语句，sort 调用不了

int cmp(int a,int b)
{
	return a>b;        // 重载小于号
}


int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};

	// 要求对 a 排序后输出

	sort(a,a+10,cmp);   // sort 传入的第一个参数，是数组名，即数组地址，第二个参数是数组要排序的长度

	for(int i=0;i<10;i++)
		printf("%d\n",a[i]);
	return 0;
}


typedef struct node
{
    int x;
    int y;

    bool operator <(const node &node1) const
    {
        return x<node1.x;
    }

}node;

#include <iostream>

#include <map>

using namespace std;



int main()

{

    map<char,int > map1;

    map<char,int>::iterator mapIter;

    //char 是键的类型，int是值的类型

    //下面是初始化，与数组类似

    //也可以用map1.insert(map<char,int >::value_type(''c'',3));

    map1['c']=3;

    map1['d']=4;

    map1['a']=1;

    map1['b']=2;
    //map1['c']=4;

    for(mapIter=map1.begin();mapIter!=map1.end();++mapIter)

        cout<<" "<<(*mapIter).first<<": "<<(*mapIter).second;

    //first对应定义中的char键，second对应定义中的int值

    //检索对应于d键的值是这样做的：

    map<char,int>::const_iterator ptr;

    ptr=map1.find('d');

    cout<<'\n'<<" "<<(*ptr).first<<" 键对应于值："<<(*ptr).second;

    return 0;

}

//其中用到了vector的成员函数：begin()，end()，push_back()，assign()，front()，back()，erase()，empty()，at()，size()。
#include <iostream>

#include <vector>

using namespace std;



typedef vector<int> INTVECTOR;//自定义类型INTVECTOR

//测试vector容器的功能



int main()

{

    //vec1对象初始为空

    INTVECTOR vec1;

    //vec2对象最初有10个值为6的元素

    INTVECTOR vec2(10,6);

    //vec3对象最初有3个值为6的元素，拷贝构造

    INTVECTOR vec3(vec2.begin(),vec2.begin()+3);

    //声明一个名为i的双向迭代器

    INTVECTOR::iterator i;

    //从前向后显示vec1中的数据

    cout<<"vec1.begin()--vec1.end():"<<endl;

    for (i =vec1.begin(); i !=vec1.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //从前向后显示vec2中的数据

    cout<<"vec2.begin()--vec2.end():"<<endl;

    for (i =vec2.begin(); i !=vec2.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //从前向后显示vec3中的数据

    cout<<"vec3.begin()--vec3.end():"<<endl;

    for (i =vec3.begin(); i !=vec3.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //测试添加和插入成员函数，vector不支持从前插入

    vec1.push_back(2);//从后面添加一个成员

    vec1.push_back(4);

    vec1.insert(vec1.begin()+1,5);//在vec1第一个的位置上插入成员5

    //从vec1第一的位置开始插入vec3的所有成员

    vec1.insert(vec1.begin()+1,vec3.begin(),vec3.end());

    cout<<"after push() and insert() now the vec1 is:" <<endl;

    for (i =vec1.begin(); i !=vec1.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //测试赋值成员函数

    vec2.assign(8,1);   // 重新给vec2赋值，8个成员的初始值都为1

    cout<<"vec2.assign(8,1):" <<endl;

    for (i =vec2.begin(); i !=vec2.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //测试引用类函数

    cout<<"vec1.front()="<<vec1.front()<<endl;//vec1第零个成员

    cout<<"vec1.back()="<<vec1.back()<<endl;//vec1的最后一个成员

    cout<<"vec1.at(4)="<<vec1.at(4)<<endl;//vec1的第五个成员

    cout<<"vec1[4]="<<vec1[4]<<endl;

    //测试移出和删除

    vec1.pop_back();//将最后一个成员移出vec1

    vec1.erase(vec1.begin()+1,vec1.end()-2);//删除成员

    cout<<"vec1.pop_back() and vec1.erase():" <<endl;

    for (i =vec1.begin(); i !=vec1.end(); ++i)

        cout << *i << " ";

    cout << endl;

    //显示序列的状态信息

    cout<<"vec1.size(): "<<vec1.size()<<endl;//打印成员个数

    cout<<"vec1.empty(): "<<vec1.empty()<<endl;//清空

}

#include <iostream>

#include <string>

#include <list>

using namespace std;



void PrintIt(list<int> n)

{

    for(list<int>::iterator iter=n.begin(); iter!=n.end(); ++iter)

      cout<<*iter<<" ";//用迭代器进行输出循环

}



int main()

{

    list<int> listn1,listn2;    //给listn1,listn2初始化

    listn1.push_back(123);

    listn1.push_back(0);

    listn1.push_back(34);

    listn1.push_back(1123);    //now listn1:123,0,34,1123

    listn2.push_back(100);

    listn2.push_back(12);    //now listn2:12,100

    listn1.sort();

    listn2.sort();    //给listn1和listn2排序

    //now listn1:0,34,123,1123         listn2:12,100

    PrintIt(listn1);

    cout<<endl;

    PrintIt(listn2);

    listn1.merge(listn2);    //合并两个排序列表后,listn1:0，12，34，100，123，1123

    cout<<endl;

    PrintIt(listn1);

}

*/
#include <iostream>

#include <set>

using namespace std;



int main()

{

    set<int> set1;

    for(int i=0; i<10; ++i)

        set1.insert(i);

    for(set<int>::iterator p=set1.begin();p!=set1.end();++p)

        cout<<*p<<"";

    if(set1.insert(3).second)//把3插入到set1中

//插入成功则set1.insert(3).second返回1，否则返回0

//此例中，集中已经有3这个元素了，所以插入将失败

        cout<<"set insert success";

    else

        cout<<"set insert failed";

    int a[] = {4, 1, 1, 1, 1, 1, 0, 5, 1, 0};

    multiset<int> A;

    A.insert(set1.begin(),set1.end());

    A.insert(a,a+10);

    cout<<endl;

    for(multiset<int>::iterator p=A.begin();p!=A.end();++p)

    cout<<*p<<" ";

    return 0;

}
