// #include <iostream> 
// using namespace std;

// class Person
// {
//     //gouzaohanshu 
//     public:
//     Person() //这个是默认构造函数
//     {
//         cout << "Person morengouzaohanshu" << endl;
//         cout << endl;
//     }

//     Person(int a) //这个是有参构造函数
//     {
//         cout << "Person youcanhuanshugouzao" << endl;
//         cout << endl;
//     }

//     Person(const Person &p) //这个是拷贝构造函数
//     {
//         cout << "kaobeigouzao" << endl;
//         cout << endl;
//         age = p.age;
//     }

//     ~Person() //这个是析构函数
//     {
//         cout << "Person xigouhanshu" <<endl;
//         cout << endl;
//     }

//     //这个是Person类的age数据特性
//     int age; 
// };

// void test01()
// {
//     Person p1;//使用默认构造函数的时候，不要加（）\
//                 否则会认为这是一个函数的声明，而不是认为在创建对象

    
//     //两种方法：1.一种是显示法来构造函数，2.另一个是括号法来构造函数
//     Person p2 = Person(10); //显示法
//     Person p2(10); //这个是括号法

//     Person p3(p2);
//     Person p3 = Person(p2);

//     //匿名对象，当前行执行结束就直接销毁对象
//     Person(10);

//     //但是可以通过这个来赋值给其他的对象 \
//     不要利用拷贝构造函数 来初始化匿名对象
//     //Person(p3);

//     cout << p2.age << endl;
//     cout << p3.age << endl;

//     //3.隐式转换法：
//     Person p4 = 10; //这是有参构造
//     Person p5 = p4; //拷贝构造

// }

// int main()
// {
//     test01();
//     return 0;
// }

//拷贝函数调用时机

//1.使用一个已经创建完毕的对象来初始化一个新对象

//2.值传递的方式来给函数参数传值

//3.值方式返回局部对象
// class Person
// {
//     public:
//     Person()
//     {
//         cout << "Person默认构造函数调用" << endl;
//     }

//     Person(int age)
//     {
//         cout << "Person有参构造函数调用" << endl;
//         m_Age = age;
//     }

//     Person(const Person &p)
//     {
//         cout << "Person拷贝构造函数调用" << endl;
//         m_Age = p.m_Age;
//     }

//     ~Person()
//     {
//         cout << "Person析构函数调用" << endl;
//     }

//     int m_Age;
// };

// void test01()
// {
//     Person p1(20);
//     Person p2(p2);

//     cout << "p2年龄为: " << p2.m_Age << endl;
// }

// void doWork(Person p)
// {

// }

// void test02()
// {
//     Person p;
//     doWork(p);
// }

// Person doWork02()
// {
//     Person p1;
//     cout << (int*)&p1 << endl;
//     return p1;
// }

// void test03()
// {
//     Person p = doWork02();
//     cout << (int*)&p << endl;
// }

// int main()
// {
//     //test01();
//     //test02();
//     test03();
//     return 0;
// }

//构造函数的调用 \
默认构造 （空实现） 析构函数 （空实现） 拷贝构造（值拷贝）

//如果我们已经写了有参构造，那么编译器不会再提供默认构造

// //
// class Person
// {
//     public:
//     Person()
//     {
//         cout << "Person的默认构造函数调用" << endl;
//     }
    
//     Person(int age)
//     {
//         cout << "Person的有参函数调用" << endl;
//         m_Age= age;
//     }

//     Person(const Person &p)
//     {
//         cout << "Person的拷贝函数调用" << endl;
//         m_Age= p.m_Age;
//     }

//     ~Person()
//     {
//         cout << "Person的析构函数调用" << endl;
//     }

//     int m_Age;
// };

// void test01()
// {
//     Person p;
//     p.m_Age = 18;

//     Person p2(p);
//     cout << "p2的年龄为: " << p2.m_Age << endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Person 
// {
//     public:
//     Person()
//     {
//         cout << "Person的默认构造函数调用" << endl; 
//     }

//     Person(int age, int height)
//     {
//         m_Age = age;
//         m_Height = new int(height);
//         cout << "Person的有参构造函数调用" << endl;
//     }

//     //所以自己需要实现拷贝构造函数，来解决浅拷贝带来的问题
//     Person(const Person &p)
//     {
//         cout << "Person 拷贝构造函数调用" << endl;
//         m_Age = p.m_Age;
//         m_Height = new int (*p.m_Height);
//     }

//     //编译器默认实现就是直接=赋值的代码
//     //但是深拷贝操作就是需要重新在堆区申请并且重新释放内存，不会产生堆区的内存重复释放的问题
//     ~Person()
//     {
//         cout << "Person的析构函数调用"  << endl;
//     }

//     int m_Age;
//     int *m_Height;
// };


// void test01()
// {
//     Person p1(18, 160);
//     cout << "p1的年龄为: " << p1.m_Age << "  身高为:  " << *p1.m_Height <<  endl;
//     Person p2(p1);
//     cout << "p2的年龄为: " << p2.m_Age << "  身高为:   " <<  *p2.m_Height << endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }

//浅拷贝带来的问题就是堆区的内存重复释放
//如果在堆区开辟了内存，一定需要在其他的地方重新深拷贝函数

// #include <iostream>
// using namespace std;

// class Person
// {
//     public:
//     // Person(int a, int b, int c)
//     // {
//     //     int m_A = a;
//     //     int m_B = b;
//     //     int m_C = c;
//     // }
//     //注意冒号的位置，冒号后面是初始化列表，冒号前面是函数体，初始化列表的方法
//     Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c)
//     {

//     }

//     int m_A;
//     int m_B;
//     int m_C;
// };

// void test01()
// {
//     Person p(30, 40, 50);
//     cout << "m_A = " << p.m_A << "  m_B = " << p.m_B << "  m_C = " << p.m_C << endl; 
// }

// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string>

// class Phone
// {
//     public:

//     Phone(string pName)
//     {
//         cout << "Phone的构造函数调用" << endl;
//         m_PName = pName;
//     }

//     ~Phone()
//     {
//         cout << "Phone的析构函数调用" << endl;
//     }
//     string m_PName;
// };

// class Person
// {
//     public:

//     //当其他类的对象作为本类成员，构造的时候先构造成员对象，然后构造本类成员
//     Person(string name, string pName): m_Name(name), m_Phone(pName)
//     {
//         //类似Phone m_Phone = pName 隐式转换法
//         cout << "Person的构造函数调用" << endl;
//     }

//     ~Person()
//     {
//         cout << "Person的析构函数调用" << endl;
//     }
//     //姓名
//     string m_Name;
//     //手机
//     Phone m_Phone;
// };

// void test01()
// {
//     Person p("张三", "华为P50");

//     cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }

//静态成员变量：所有对象共享同一份数据，在编译阶段分配内存，类内声明，类外初始化
//静态成员函数：所有对象共享同一份函数，静态成员函数这能访问静态成员变量

// #include <iostream>
// using namespace std;

// class Person 
// {
//     public:
//     static int m_Age;
//     //1 所有对象共享同一份数据，
//     //2.在编译阶段分配内存
//     //3.类内声明，类外初始化
//     private:
//     static int m_Height;
// };

// int Person::m_Age = 100;

// void test01()
// {
//     Person p1;
//     cout << "p的年龄为: " << p1.m_Age << endl;

//     Person p2;
//     p2.m_Age = 200;

//     cout << "p2的年龄为: " << p2.m_Age << endl;
//     cout << Person::m_Age << endl;

//     // cout << Person::m_Height << endl;私有成员变量不能访问
// }
// //这个是所有对象共享同一份数据，所以m_Age被修改 
// //静态成员变量不属于某个对象， 所有对象都可以共享

// //1. 通过对象进行访问
// //2. 通过类名进行访问
// //3. 通过指针访问

// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Person
// {
//     public:
//     static void func()
//     {
//         m_Age = 200; //静态成员函数只能访问静态成员变量
//         //m_Height = 180; //错误，静态成员函数不能访问非静态成员变量,原因是因为静态成员函数不属于任何对象，所以无法访问非静态成员变量
//         cout << "static void func调用" << endl;
//     }

//     static int m_Age;
//     int m_Height;

//     //静态成员函数也是有访问权限的
//     private:
//     static void func2()
//     {
//         cout << "static void func2调用" << endl;
//     }
// };

// int Person::m_Age = 100;
// //int Person::m_Height = 180;

// void test01()
// {
//     //1.通过对象进行访问静态成员函数
//     Person p;
//     p.func();

//     //2.通过类名来访问静态成员函数
//     Person::func();
//     // Person::func2();   //静态成员函数也是有访问权限的，私有成员函数只能通过类内的其他成员函数来访问
// }
// int main()
// {
//     test01();
//     return 0;
// // }
// #include <iostream>
// using namespace std;

// class Person
// {
//     public:
//     int m_Age;
//     static int m_Height; //静态成员变量不属于某个类的对象
//     void func() //非静态成员函数不属于类的对象
//     {
//         cout << "func调用" << endl; 
//     }
// };

// int Person:: m_Height = 180;
// void test01()
// {
//     Person p;
//     //空对象占用内存空间为：1
//     //C++编译器会给空对象分配一个字节的内存空间，来区分不同的对象
//     // 每个空对象也应该有一个独一无二的地址
//     cout << "sizeof(p) = " << sizeof(p) << endl; //空类的大小为1，空类也会占用一个字节的内存空间，来区分不同的对象
// }

// int main()
// {
//     test01();
//     return 0;
// }

//this指针：指向被调用的成员函数所属的对象，隐含在所有非静态成员函数中

// #include <iostream>
// using namespace std;

// class Person
// {
//     public:
//     Person(int age)
//     {
//         this->age = age;
//     }
//     //this指针：指向被调用成员函数所属对象      
//     //隐含在所有非静态成员函数中

//     Person& PersonAddAge(Person &p)
//     {
//         this->age += p.age;
//         //this指向p2的指针，那么*this指向的就是p2这个对象的本体
//         return *this; //返回当前对象的本体
//     }

//     int age;

// };

// //1.解决名称冲突,需要良好的命名规范
// void test()
// {
//     Person p1(18);
//     cout << "p的年龄为: " << p1.age << endl;

//     Person p2(10);//链式编程思想
//     p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//     cout << "p2的年龄为: " << p2.age << endl;
// }

// int main()
// {
//     test();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Person 
// {
//     public:
//     void showClassName()
//     {
//         cout << "this is Person class" << endl;
//     }

//     void showPersonAge()
//     {
//        if (this == NULL)
//        {
//             return ;
//        }
//     //害怕传null指针，所以加上判断，防止代码崩溃，可以保证代码的鲁棒性

//        cout << " age = " << this->m_Age << endl;
//     }

//     int m_Age;
// };

// void test01()
// {
//     Person *p = NULL;

//     p->showClassName(); //this is Person class
//     p->showPersonAge(); //age = 0 这里this指针是空指针，而且访问下面的成员，传入的指针为NULL，无中生有得到NULL
// }

// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// //常函数 常对象
// class Person
// {
//     public:
//     void showPerson() const //修饰的是this指针，让指针的指向的值也不可以修改
//     {
//         //this->m_A = 100; //this 指针不可以修改指针的 指向
//     }

//     int m_A;
//     mutable int m_B; //mutable 关键字修饰的成员变量，（意思是可变的）特殊变量，即使在常函数中也可以修改这个值
// };

// void test()
// {
//     Person p;
//     p.showPerson();
//     //p.m_A = 100;//这里对象前面加上const，变为常对象，常对象只能调用常函数，常函数不能修改成员变量的值，所以这里会报错
//     p.m_B = 200;
//     //常对象只能调用常函数，常函数不能修改成员变量的值（成员属性），所以这里会报错
// }

// int main()
// {
//     test();
//     return 0;
// }

//访问私有的内容
//友元的三种实现 1.全局函数做友元 2.类作为友元 3.成员函数作为友元


// #include <iostream> 
// using namespace std;

// class Building
// {
//     friend void goodGay(Building *building); 
//     //goodgay全局函数是building中的好朋友，可以访问building中的私有成员
//     public:
//     Building()
//     {
//         m_SittingRoom = "客厅";
//         m_bedroom = "卧室";
//     }

//     public:
//     string m_SittingRoom;

//     private:
//     string m_bedroom;

// };
// void goodGay(Building *building)
// {
//     cout << "好基友全局函数正在访问: " << building->m_SittingRoom << endl;
//     cout << "好基友全局函数正在访问: " << building->m_bedroom << endl;
// }
// int main()
// {
//     Building building;
//     goodGay(&building);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string>

// class Building;

// class GoodGay
// {
// public:
// 	GoodGay();

// 	void visit(); //参观函数 访问Building中的属性
// 	void visit2();

// 	Building *building;

// };

// class Building
// {
// 	friend class GoodGay; //告诉编译器goodgay类是building类的好朋友，可以访问building类中的私有内容
// 	friend void GoodGay::visit(); //告诉编译器goodgay类中的visit函数是building类的好朋友，可以访问building类中的私有内容
// 	//这个就是成员函数作为友元函数，访问权限是单独的，visit2函数就访问不了building类中的私有内容了
// public:
// 	Building();

// public:
// 	string m_SittingRoom;

// private:
// 	string m_Bedroom;

// };

// Building::Building()
// {
// 	m_SittingRoom = "客厅";
// 	m_Bedroom = "卧室";
// }

// GoodGay::GoodGay()
// {
// 	building = new Building;
// }

// void GoodGay::visit()
// {
// 	cout << "正在访问： " << building->m_SittingRoom << endl;
// 	cout << "正在访问： " << building->m_Bedroom << endl; //访问不到
// }

// void GoodGay::visit2()
// {
// 	cout << "正在访问： " << building->m_SittingRoom << endl;
// 	cout << "正在访问： " << building->m_Bedroom << endl; //访问不到
// }

// void test1()
// {
// 	GoodGay gg;
// 	gg.visit();
// 	gg.visit2();
// }

// int main()
// {
// 	test1();
// 	return 0;
// }

//对于内置的数据类型，编译器知道如何进行运算，
//但是对于自定义的数据类型，编译器不知道如何进行运算，所以需要我们重载运算符，来告诉编译器如何进行运算


// #include <iostream>
// using namespace std;

// //对于运算符重载可以通过成员函数重载也可以通过全局函数重载
// //函数名称是编译器起名的，函数名称是固定的，不能随便起名
// class Person
// {
// public:

//     Person operator+(Person &p) //重载+运算符，返回值类型是Person对象，参数是一个Person对象的引用
//     {
//         Person temp; //创建一个临时对象来存储结果
//         temp.m_A = this->m_A + p.m_A; //this指针指向当前对象，p是传入的对象
//         temp.m_B = this->m_B + p.m_B;
//         return temp; //返回临时对象
//     }
//     //以上是成员函数的重载

//     int m_A;
//     int m_B;
// };

// //全局函数的重载+
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A; //p1和p2是传入的对象
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp; //返回临时对象
// };

// //函数重载的版本
// Person operator+(Person &p1, int num)
// {
//     Person temp;
//     temp.m_A = p1.m_A + num;
//     temp.m_B = p1.m_B + num;
//     return temp;
// }

// void test()
// {
//     Person p1;
//     p1.m_A = 10;
//     p1.m_B = 20;
    
//     Person p2;
//     p2.m_A = 30;
//     p2.m_B = 114514;

//     //这就是全局函数的调用

//     //Person p3 = p1 + p2; //调用重载的+运算符，返回一个Person对象

//     //Person p3 = p1.operator+(p2); //调用成员函数的重载+运算符，返回一个Person对象

//     //Person p3 = operator+(p1, p2); //调用全局函数
//     Person p3 = operator+(p1, p2);

//     //运算符重载，也可以发生函数重载
//     Person p4 = p1 + 100;

//     //这个是一个输出
//     cout << "p3.m_A = " << p3.m_A << "  p3.m_B = " << p3.m_B << endl;   
//     cout << "p4.m_A = " << p4.m_A << "  p4.m_b = " << p4.m_B << endl;
// }

// int main()
// {
//     test();
//     return 0;
// }

//总结！！！：内置的数据类型的表达式的运算符是不可能改变的
//不要滥用运算符重载，运算符重载的本质就是函数调用，重载的运算符函数名称是固定的，不能随便起名

// #include <iostream>
// using namespace std;

// class  Person
// {
//     friend ostream & operator<<(ostream &cout, Person &p);
    
//     public:
//     Person(int a, int b)
//     {
//         m_A = a;
//         m_B = b;
//     }

//     //利用成员函数重载左移运算符
//     private:
//     int m_A;
//     int m_B;

// };

// //只能利用全局函数重载左移运算符
// //cout就是标准的输出流对象，使用引用的方式传递
// //全局函数访问成员的方式：友元
// ostream & operator<<(ostream &cout, Person &p)
// {
//     cout <<  "m_A = " << p.m_A << " m_B = " << p.m_B ;
//     return cout;
// }

// void test()
// {
//     Person p(10, 10);

//     cout << p << endl;
// }

// int main()
// {
//     test();
//     return 0;
// }

//重载左移运算符：希望这里直接输出对应的对象而不是输出对应对象的值

//希望得出输出流 这里的左移运算符配合运算符重载可以实现自定义的这种输出类型


// #include <iostream>
// using namespace std;

// //递增运算符重载++
// //先来了解数据类型对应的输出结果


// //重载递增运算符
// class MyInteger
// {
//     friend ostream& operator<<(ostream &cout, MyInteger myint);
// public:
//     MyInteger()
//     {
//         m_Num = 0;
//     }
//     //重载++运算符（前置和后置的递增运算符）
//     MyInteger& operator++()//!!!返回引用是为了一直使用一个数据进行操作
//     {
//         m_Num++;//先进行++运算

//         //将自身作为返回
//         return *this;
//     }

//     MyInteger operator++(int) //int代表占位参数，可以用于区分前置后置的递增
//     {
//         //先记录当时的结果
//         MyInteger temp = *this;
//         //后递增
//         m_Num++;
//         //最后将记录结果作为返回
//         return temp;
//     }
// private:
//     int m_Num;

// };

// ostream& operator<<(ostream &cout, MyInteger myint)
// {
//     cout << myint.m_Num;
//     return cout;
// }

// void test01()
// {
//     MyInteger myint;
//     //自定义函数运算符不知道怎么做-全局函数实现左移自定义运算符
//     cout << ++(++myint) << endl;
//     cout << myint << endl;
// }

// void test02()
// {
//     MyInteger myint;

//     cout << myint++ << endl;
//     cout << myint << endl;

// }
// int main()
// {
//     int a = 0;

//     cout << ++(++a) << endl;
//     cout << a << endl;

//     test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// //c++编译器至少给一个类添加4个函数
// //1.默认构造函数（没有参数），函数体为空
// //2.默认析构函数，同上
// //3.默认拷贝构造函数，对属性进行值拷贝
// //4.赋值运算符operator，对属性进行拷贝

// class Person
// {
// public:

//     Person(int age)
//     {
//         m_Age = new int(age);
//     }

//     ~Person()
//     {
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }
//     }

//     Person& operator=(Person &p)
//     {
//         //编译器提供浅拷贝,应该先判断是否有属性在堆区，如果有就释放干净，然后再深拷贝
//         // m_Age = p.m_Age;
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }

//         //这里就是深拷贝
//         m_Age = new int(*p.m_Age);

//         return *this;
//     }

//     int *m_Age;
// };

// void test01()
// {
//     Person p1(18);

//     Person p2(20);
    
//     Person p3(30);

//     p3 = p2 = p1;//但是这里面的数据类型不能实现连等,实际上为了实现链式编程

//     cout << "p1的年龄为: " << *p1.m_Age << endl;
//     cout << "p2的年龄为: " << *p1.m_Age << endl;
//     cout << "p3的年龄为: " << *p1.m_Age << endl;
//     //堆区的内存重复释放，导致程序崩溃

//     //重载赋值运算符

// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = 30;

//     c = b = a;
//     cout << "a = " << endl;
//     cout << "b = " << endl;
//     cout << "c = " << endl;
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         m_Name = name;
//         m_Age = age;
//     }

//     bool operator==(Person &p)
//     {
//         if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//         {
//             return true;
//         }
//         return false;
//     }

//     bool operator!=(Person &p)
//     {
//         if (this->m_Name != p.m_Name && this->m_Age != p.m_Age)
//         {
//             return true;
//         }
//         return false;
//     }

//     string m_Name;
//     int m_Age;

// };

// void test01()
// {
//     Person p1("Tom", 18);

//     Person p2("jim", 18);

//     if (p1 == p2)
//     {
//         cout <<"p1和p2是相等的" << endl;
//     }
//     else 
//     {
//         cout << "p1和p2不相等的" << endl;
//     }

//     if (p1 != p2)
//     {
//         cout << "p1和p2不相等的" << endl;
//     }
// }

// int main()
// {
//     test01();
//     return 0;
// }

//函数调用运算符（）也可以重载，由于重载后的使用方式非常像函数的调用，
// 因此称为仿函数，仿函数没有固定写法，所以非常灵活


// #include <iostream>
// using namespace std;
// //函数调用运算符重载
// //打印输出类

// class MyPrint
// {
// public:

// //重载函数调用运算符
//     void operator()(string test)
//     {
//         cout << test <<endl;
//     }
// };

// void MyPrint2(string test)
// {
//     cout << test << endl;
// }

// void test1()
// {
//     MyPrint myPrint;

//     myPrint("hello world, this is cpp");

//     MyPrint2("hello world");
//     //使用起来特别类似于函数的调用，因此成为仿函数 
// }

// class MyAdd
// {
// public://仿函数非常灵活，可以写各种各样的函数类型
//     int operator()(int num1, int num2)
//     {
//         return num1 + num2;
//     }

// };

// void test2()
// {
//     MyAdd myadd;
//     int ret = myadd(100, 100);//仿函数的写法非常灵活，stl等等都有
//     cout << "ret = " << ret << endl;

//     cout << MyAdd()(100, 114514) << endl;//这里创建的是匿名对象
// }
// int main()
// {
//     test1();
//     test2();
//     return 0;
// }

//继承是面向对象的3大特性，继承的技术

// #include <iostream>
// using namespace std;

// class BasePage
// {
// public:
//     void header()
//     {
//         cout << "首页，公开课，登录，注册（公共头部）" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心，交流合作，站内地图（公共底部）" << endl;
//     }
//     void left()
//     {
//         cout << "Java, Python, c++(公共分类的列表)" << endl; 
//     }
// };

// //Java页面
// class Java : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }
// };

// //Python页面
// class Python : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Python学科视频" << endl;
//     }
// };

// //c++页面
// class cpp : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "C++学科视频" << endl;
//     }
// };

// //继承的好处：减少重复的代码
// //语法：class 子类 ：继承方式 父类
// //子类也称为派生类
// //父类也称为基类
// void test1()
// {
//     cout << "Java下载视频页面如下： " << endl;
//     Java ja;
//     ja.header();
//     ja.footer();
//     ja.left();
//     ja.content();

//     cout << "Python下载视频页面如下： " << endl;
//     Python py;
//     py.header();
//     py.footer();
//     py.left();
//     py.content();
    
//     cout << "C++下载视频页面如下： " << endl;
//     cpp cp;
//     cp.header();
//     cp.footer();
//     cp.left();
//     cp.content();
    
// }
// //共性与个性的区别：继承
// int main()
// {
//     test1();//继承可以方便写完很多重复的代码，使得逼格提升
//     return 0;
// }

//继承有很多的继承方式：公共继承，保护继承，私有继承

// #include <iostream>
// using namespace std;

// class Base1
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;

// }; 

// class Son1 : public Base1
// {
// public:
//     void func()
//     {
//         m_A = 10;//父类中的公共权限成员，到子类中依然是公共权限
//         m_B = 10;//父类中的公共保护成员，到子类中依然是保护权限
//         // m_C = 10;//父类中的私有权限成员，子类访问不到
//     }
// };

// //保护继承
// void test1()
// {
//     Son1 s1;
//     s1.m_A = 100;
//     // s1.m_B = 100;//保护权限中，类外是访问不到的  
// }
// class Base2
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;
// };

// class Son2 : protected Base2
// {
// public:
//     void func2()
//     {
//         m_A = 100;
//         m_B = 100;
//         //父类中的私有成员，子类中变为保护权限
//     }
// };

// void test2()
// {
//     Son2 s2;
//     // s2.m_A = 1000; 这里son2中已经变为了保护权限，所以类外已经访问不到了
//     // s2.m_B = 1000; 同理这里是保护权限，不可以访问
// }

// class Base3
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;
// };

// class Son3: private Base3
// {
//     private:
//     void func()
//     {
//         m_A = 1;    //父类中公共成员，到子类中变为私有成员
//         m_B = 1;    //父类中保护成员，到子类中变为私有成员
//         // m_C = 1; //父类中私有成员，子类访问不到
//     }
// };

// void test3()
// {
//     Son3 s1;
// }

// class GrandSon : public Son3
// {
//     void func()
//     {
//         // m_A = 0;
//     }
// };

// int main()
// {
//     test1();
//     test2();
//     test3();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;
// };

// class Son : public Base
// {
// public:
//     int m_D;
// };

// void test1()
// {
//     cout << "size of son = " << sizeof(Son) << endl;
// }

// int main()
// {
//     test1();//父类中所有非静态成员属性都会被子类继承下去
//         //父类中私有成员属性是被编译器给隐藏了，因此访问不到，但是确实是被继承下去了
//     return 0;
// } 
//可以使用命令提示符来看

//利用开发人员命令提示工具来查看对象模型-利用开发人员命令提示工具查看对象类型

//继承中的构造和析构顺序
//父类和子类的构造和析构顺序是谁先谁后

// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     Base()
//     {
//         cout << "Base构造函数" << endl;
//     }

//     ~Base()
//     {
//         cout << "Base析构函数" << endl;
//     }
// };

// class Son:public Base
// {
// public: 
//     Son()
//     {
//         cout << "Son构造函数" << endl;
//     }

//     ~Son()
//     {
//         cout << "Son析构函数" << endl;
//     }
// };

// void test1()
// {
//     Son s;
// }

// int main()
// {
//     test1();
//     return 0;
// }

//继承共同成员处理方式 如何通过子类对象，访问子类或者父类中同名的数据 

//访问子类同名成员，直接访问即可
//访问父类同名成员，需要加作用域

// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     Base()
//     {
//         m_A = 100;
//     }

//     void func()
//     {
//         cout << "father - func()调用" << endl;
//     }

//     void func(int a)
//     {
//         cout << "father - func(int a) 调用" << endl;
//     }

//     int m_A;
// };

// class Son: public Base
// {
// public:
//     Son()
//     {
//         m_A = 200;
//     }

//     void func()
//     {
//         cout << "son - func()函数调用" << endl;
//     }

//     int m_A;
// };

// void test1()
// {
//     Son s;
//     cout << "son m_A = " << s.m_A << endl;
//     //如果通过子类对象，访问到父类中的同名成员，需要加作用域
//     cout << "father m_A = " << s.Base::m_A << endl;
// }

// //同名成员属性的处理方式
// void test2()
// {
//     Son s;

//     s.func(); //直接调用 调用是子类中的同名成员

//     s.Base::func(); //调用父类中同名的成员函数

//     //如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名成员
//     //需要加上作用域，否则无法访问父类中的成员函数
//     s.Base::func(100);
// }

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }

//1.子类对象可以直接访问到子类中的同名成员
//2.子类对象加作用域可以访问到父类中的同名成员
//3.当子类与父类拥有同名的成员函数吗，子类会隐藏父类中的同名成员函数，加上作用域可以访问到父类中的同名函数

// #include <iostream>
// using namespace std;
// class Base
// {
// public:
//     static int m_A;

//     static void func()
//     {
//         cout << "Base - func()调用" << endl;
//     }

//     static void func(int a)
//     {
//         cout << "Base - func(int a)调用" << endl;
//     }

// };

// int Base::m_A = 100;

// class Son : public Base
// {
// public:
//     static int m_A;

//     static void func()
//     {
//         cout << "Son - func()调用" << endl;
//     }
// };

// int Son::m_A = 200;
// //同名静态成员属性的处理方式

// void test1()
// {
//     //1.通过对象进行访问
//     cout << "通过对象进行访问" << endl;
//     Son s;
//     cout << "son m_A = " << s.m_A << endl;
//     cout << "father m_A = " << s.Base::m_A << endl;

//     //2.通过类名进行访问
//     cout << "通过类名进行访问" << endl;
//     cout << "son m_A = " << Son::m_A << endl;
//     cout << "father m_A = " << Son::Base::m_A << endl;
//     //同名的静态成员属性的处理方式和非静态成员属性的处理方式一样，访问父类中的同名成员需要加上作用域
// }

// void test2()
// {
//     //1.通过对象的方式访问
//     Son s;
//     s.func();
//     s.Base::func();

//     //2.通过类名的方式访问
//     Son::func();

//     Son::Base::func();

//     Son::Base::func(100);
//     //子类出现和父类同名的静态成员函数，也会隐藏父类中的所有同名成员函数
//     //访问父类中的同名成员函数需要加上作用域
// }

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }
//同名静态成员处理方式和非静成员的处理方式一样，只不过有两种不同的访问方式（通过对象或者是类名）


//多继承的语法
// #include <iostream>
// using namespace std;

//多继承可能会引发父类中有同名的成员出现，需要加上作用域区分

//多继承的语法

// class Base1
// {
// public:
//     Base1()
//     {
//         m_A = 100;
//     }

//     int m_A;
// };

// class Base2
// {
// public:
//     Base2()
//     {
//         m_B = 200;
//     }

//     int m_B;
// };

// class Son: public Base1, public Base2
// {
// public:
//     Son()
//     {
//         m_C = 300;
//         m_D = 400;
//     }

//     int m_C;
//     int m_D;
// };

// void test1()
// {
//     Son s;

//     cout << "size of son = " << sizeof(s) << endl;
//     //多继承会导致父类中同名成员出现，需要加上作用域,也就是二义性出现了，需要修改，！！！需要加上作用域来区分
// }

// int main()
// {
//     test1();
//     return 0;
// }l

//通常来说不是很建议在实际开发中使用多继承的语法，带来满麻烦

// #include <iostream>
// using namespace std;

// //菱形继承：两派生类继承同一个基类，又有某个类同时集成两个派生类
// class Animal
// {
// public:
//     int m_Age;
// };

// //虚继承用来解决菱形继承的问题
// //Animal类称为虚基类
// //在继承之前，加上关机子virtual变为虚继承，解决了二义性问题，编译器会帮我们合成一份数据，来共享给两个派生类使用

// class sheep : virtual public Animal
// {

// };
 
// class goat : public Animal
// {

// };

// class SheepGoat : public sheep, public goat
// {

// };

// void test1()
// {
//     SheepGoat sg;

//     //需要知道作用域才能知道具体的访问哪个父类中的成员，二义性出现了

//     sg.sheep::m_Age = 100; //二义性，编译器不知道访问哪个父类中的m_Age，需要加上作用域来区分
//     sg.goat::m_Age = 200;  //二义性，编译器不知道访问哪个父类中的m_Age，需要加上作用域来区分
//     cout << "sheep的年龄为: " << sg.sheep::m_Age << endl;
//     cout << "goat的年龄为: " << sg.goat::m_Age << endl;

//     //编译器会帮我们合成一份数据，来共享给两个派生类使用，二义性问题解决了
//     //这份数据我们知道，只有一份就可以，菱形继承数据有两份，资源浪费
//     //vbptr代表的是虚基类指针-- virtual base pointer  
// }

// int main()
// {
//     test1();
//     return 0;
// }
// //菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
// //虚继承可以解决菱形继承问题

// #include <iostream>
// #include <stdio.h>
// using namespace std;

// int main()
// {
//     int x = -1, z = 2147483647;
//     unsigned int y = x;
//     printf("x = %d, y = %u, z = %d\n", x, y, z+1);

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main(){
// 	int a=0,b=0;
// 	cout<<"1 "<<"2 "<<"3 "<<endl;
// 	cout<<b++<<" "<<b++<<" "<<b++<<endl;
// 	cout<<++a<<" "<<++a<<" "<<++a<<endl;  
// 	return 0; 
// }

// #include <iostream>
// using namespace std;

// void swapInt(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swapDouble(double &a, double &b)
// {
//     double temp = a;
//     a = b;
//     b = temp;
// }

// template<typename T> //声明一个模板，告诉编译器后面代码紧跟着T不要报错，T是一个通用的数据类型
// void mySwap(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// void test1()
// {
//     int a = 10;
//     int b = 20;

//     double c = 1.1;
//     double d = 1.2;

//     // swapInt(a, b);
//     // mySwap(a,b);
//     mySwap<int>(a,b);

//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     // swapDouble(c, d);
//     // cout << "c = " << c << endl;
//     // cout << "d = " << d << endl;
// }

// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template<class T> //typename可以替换成class
// void mySwap(T &a, T&b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// void test1()
// {
//     int a = 10;
//     int b = 20;

//     mySwap(a, b);

//     cout << "a = " << a << endl;

//     cout << "b = " << b << endl;
// }
// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;

// void test1()
// {
//     ofstream ofs;

//     ofs.open("test.txt", ios::out);
//     ofs << "name : harry" << endl;
//     ofs << "age = 19" << endl;
//     ofs << "gender : male" << endl;

//     ofs.close();
// }

// int main()
// {   
//     test1();
//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// void test1()
// {
//     //1.include header file 
//     //2.create the objextive of stream
//     ifstream ifs;
    
//     //3.open the file and judge whether it is open successfully
//     ifs.open("test.txt", ios::in);
//     //4.read the data
//     if (!ifs.is_open()) 
//     {
//         cout << "the file is unable to open!" << endl;
//         return;
//     }
    //5.close the file
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    // ifs.close();

    // char buf[1024] = {0};
    // while (ifs.getline(buf,sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    // string buf;

    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }
//     char c;
//     while ((c = ifs.get()) != EOF)
//     {
//         cout << c;
//     }
// }

// int main()
// {
//     test1();
//     return 0;

// }

// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// class Person
// {
// public:
//     char m_Name[64];
//     int m_Age;
// };

// void test1()
// { 
//     ofstream ofs("test.txt" , ios::out | ios::binary);
//     Person p = {"zhangsan" , 18};

//     ofs.write((const char*)&p, sizeof(p));

//     ofs.close();
// }

// int main()
// {
//     test1();
//     return 0;
// }

// void test1()
// {
//     ifstream ifs;

//     ifs.open("test.txt", ios::in | ios::binary);

//     if (!ifs.is_open())
//     {
//         cout << "the file is unable to open" << endl;
//         return;
//     }

//     Person p;
//     ifs.read((char *)&p, sizeof(Person));

//     cout << "name: " << p.m_Name << "age: " << p.m_Age << endl;
//     ifs.close();
// }

// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// template<class T>
// void mySwap(T&a, T&b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// template<class T>
// void mySort(T arr[], int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         int max = i; 
//         for (int j = i + 1; j < len; j++)
//         {
//             //我们认定的最大值比便利的数值要小，j才是真正最大值
//             if (arr[max] < arr[j])
//             {
//                 max = j;
//             }
//         }
//         if (max != i)
//         {
//             mySwap(arr[max], arr[i]);
//         }
//     }
// }

// template<class T>
// void printArray(T arr[], int len)
// {
//     for (int i = 0; i < len ; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// void test1()
// {
//     char charArr[] = "badcfe";
//     int num = sizeof(charArr) / sizeof(char);
//     mySort(charArr, num);
//     printArray(charArr, num);
// }

// void test2()
// {
//     int intArr[] = {7,5,1,3,9,2,4,6,8};
//     int num = sizeof(intArr) / sizeof (int);

//     mySort(intArr, num);
//     printArray(intArr, num);
// }

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int myAdd1(int a, int b)
// {
//     return a + b;
// }

// template<class T>
// T myAdd2(T a, T b)
// {
//     return a + b;
// }

// void test1()
// {
//     int a = 10;
//     int b = 20;
//     char c = 'c';
//     cout << myAdd1(a, c) << endl;

//     cout << myAdd2<int>(a, c) << endl;
// }

// int main()
// {
//     test1(); 
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void myPrint(int a, int b)
// {
//     cout << "the use of ordinary function" << endl;
// }

// template<class T>
// void myPrint(T a, T b)
// {
//     cout <<  "the use of template function" << endl;
// }

// void test1()
// {
//     int a = 10;
//     int b = 20;

//     // myPrint(a, b);

//     myPrint<>(a,b);
// }

// int main()
// {
//     test1();
//     return 0;
// }
// #include <iostream>
// using namespace std;

// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         this->age = age;
//         this->name = name;
//     }

//     string name;
//     int age;
// };

// template<class T>
// bool myCompare(T &a, T &b)
// {
//     if (a == b)
//     {
//         return true;
//     }
//     else 
//     {
//         return false;
//     }
// }

// template<> bool myCompare(Person &p1, Person &p2)
// {
//     if (p1.name == p2.name && p1.age == p2.age)
//     {
//         return true;
//     }
//     else 
//     {
//         return false;
//     }
// }
// void test1()
// {
//     int a = 10;
//     int b = 20;

//     bool ret = myCompare(a, b);

//     if (ret)
//     {
//         cout << "equal" << endl;
//     }
//     else 
//     {
//         cout << "unequal" << endl;
//     }
// }

// void test2()
// {
//     Person p1("tom" , 10);
//     Person p2("jack", 20);
    
//     bool ret = myCompare(p1, p2);
//     if (ret)
//     {
//         cout << "p1 p2 equal" << endl;
//     }
//     else 
//     {
//         cout << "p1 p2 unequal" << endl;
//     }
// }

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }

//

// #include <iostream>
// #include <string>
// using namespace std;

// template<class NameType, class AgeType>

// class Person
// {
// public:
//     Person(NameType name, AgeType age)
//     {
//         this->m_Name = name;
//         this->m_Age = age;
//     }

//     void showPerson()
//     {
//         cout << "name: " << this->m_Name << endl << "age: " << this->m_Age << endl;
//     }
//     NameType m_Name;
//     int m_Age;
// };

// void test1()
// {
//     Person<string, int> p1("monkey", 999);
//     p1.showPerson();
//     Person<string, int> p2("lin", 1000);  
//     p2.showPerson();
// }

// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template<class NameType, class AgeType = int>
// class Person
// {
//     public:
//     Person(NameType name, AgeType age)
//     {
//         this->m_Name = name;
//         this->m_Age = age;
//     }

//     void showPerson()
//     {
//         cout << "name: " << this->m_Name << endl << "age: " << this->m_Age << endl;
//     }

//     NameType m_Name;
//     AgeType m_Age;
// };

// void test1()
// {
//     Person<string, int> p1("lin", 1000);
//     p1.showPerson();
// }

// void test2()
// {
//     Person<string>p2("monkey", 100);
//     p2.showPerson();
// }

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }
//
// #include <iostream>
// using namespace std;
//
// class Person1
// {
//     public:
//     void showPerson1()
//     {
//         cout << "Person1 show" << endl;
//     }
// };
//
// class Person2
// {
//     public:
//     void showPerson2()
//     {
//         cout << "Person2 show" << endl;
//     }
// };
//
// template<class T>
// class MyClass
// {
//     public:
//
//     T obj;
//
//     void func1()
//     {
//         obj.showPerson1();
//     }
//
//     void func2()
//     {
//         obj.showPerson2();
//     }
// };
//
// void test1()
// {
//     MyClass<Person1> m;
//     m.func1();
//     // m.func2();
// }
// int main()
// {
//     test1();
//     return 0;
// }
//
// #include <iostream>
// using namespace std;
//
// class Person1
// {
// public:
//     void showPerson1()
//     {
//         cout << "Person1 show" << endl;
//     }
// };
//
// class Person2
// {
// public:
//     void showPerson2()
//     {
//         cout << "Person2 show" << endl;
//     }
// };
//
// template<class T>
// class Myclass
// {
// public:
//     T obj;
//
//     void func1()
//     {
//         obj.showPerson1();
//     }
//
//     void func2()
//     {
//         obj.showPerson2();
//     }
// };
//
// void test1()
// {
//     Myclass<Person1> m;
//     m.func1();
//     // m.func2();
// }
//
// int main()
// {
//     test1();
//     return 0;
// }
//
// #include <iostream>
// using namespace std;
//
// template<class T1, class T2>
// class Person
// {
// public:
//
//     Person(T1 name, T2 age)
//     {
//         this->m_Name = name;
//         this->m_Age = age;
//     }
//
//     void showPerson()
//     {
//         cout << "name: " << this->m_Name << endl << "age: " << this->m_Age << endl;
//     }
//
//     T1 m_Name;
//     T2 m_Age;
// };
//
// //the most common way to use!!!
// void printPerson1(Person<string, int> &p)
// {
//     p.showPerson();
// }
//
// template<class T1, class T2>
// void printPerson2(Person<T1, T2> &p)
// {
//     p.showPerson();
//     cout << "T1: " << typeid(T1).name() <<endl;
//     cout << "T2: " << typeid(T2).name() <<endl;
// }
//
// template<class T>
// void printPerson3(T &p)
// {
//     p.showPerson();
//     printPerson3(p);
// }
//
// void test1()
// {
//     Person<string, int>p("wukong", 100);
//     printPerson1(p);
// }
//
// void test2()
// {
//     Person<string, int>p("bajie", 90);
//     printPerson2(p);
// }
//
// void test3()
// {
//     Person<string, int> p("tangseng", 30);
//     p.showPerson();
// }
//
// int main()
// {
//     test1();
//     test2();
//     test3();
//     return 0;
// }
//
//
// #include <iostream>
// using namespace std;
//
// template<class T>
// class Base
// {
//     T m;
// };
//
// class Son : public Base<int>
// {
//     //必须知道父类中的T类型，才能继承给子类
//
// };
//
// void test1()
// {
//     Son s1;
// }
//
// template<class T1, class T2>
// class Son2 : public Base<T2>
// {
// public:
//     Son2()
//     {
//         cout << "T1 type: " << typeid(T1).name() << typeid(T1).name() << endl;
//         cout << "T2 type: " << typeid(T1).name() << typeid(T2).name() << endl;
//     }
//     T1 obj;
// };
//
// void test2()
// {
//     Son2<int, char>S2;
// }
//
// int main()
// {
//     test2();
//     return 0;
// }
//
//
//
//
// #include <iostream>
// using namespace std;
//
// template<class T1, class T2>
// class Person
// {
// public:
//      Person(T1 name, T2 age);
// //     {
// //         this->m_Name = name;
// //         this->m_Age = age;
// //     }
//     //
//     void showPerson();
//     // {
//     //     cout << "Name: " << this->m_Name << endl << "Age: " << this->m_Age << endl;
//     // }
//
//     T1 m_Name;
//     T2 m_Age;
// };
//
// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
//     this->m_Name = name;
//     this->m_Age = age;
// }
//
// template<class T1, class T2>
// void Person<T1, T2>::showPerson()
// {
//     cout << "Name: " << this->m_Name << endl << "Age: " << this->m_Age << endl;
// }
//
// void test1()
// {
//     Person<string, int> p("tom", 30);
//     p.showPerson();
// }
//
// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template<class T1, class T2>
// class Person
// {
// public:
//     Person(T1 name, T2 age);

//     void showPerson();

//     T1 m_Name;
//     T2 m_Age;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
//     this->m_Name = name;
//     this->m_Age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::showPerson()
// {
//     cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
// }

// void test1()
// {
//     Person <string, int>p("jerry", 18);
//     p.showPerson();
// }

// int main()
// {
//     test1();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << " hello world , this is my first program in cursor" << endl;
//     return 0;
// }

//类模板与函数模板的区别
// #include "person.hpp"
// #include <iostream>
// #include <string>
// using namespace std;

// // template<class T1, class T2>
// // class Person 
// // {
// // public:
// //     Person(T1 name, T2 age);

// //     void showPerson();

// //     T1 m_Name;
// //     T2 m_Age;
    
// // };

// // template<class T1, class T2>
// // Person<T1, T2>::Person(T1 name, T2 age)
// // {
// //     this->m_Name = name;
// //     this->m_Age = age;
// // }

// // template<class T1, class T2>
// // void Person<T1, T2>::showPerson()
// // {
// //     cout << "name: " << this->m_Name << endl <<  "age: " << this->m_Age << endl;
// // }

// void test1()
// {
//     Person<string, int> p("jerry", 18);
//     p.showPerson();
// }

// int main()
// {
//     test1();
//     return 0;
// } 

// #include <iostream>
// using namespace std;

// template<class T1, class T2>
// class Person;

// template<class T1, class T2>
// void printPerson2(Person<T1, T2> p)
// {
//     cout << "Name2: " << p.m_Name << endl << "Age: " << p.m_Age << endl; 
// }

// template<class T1, class T2>
// class Person
// {
//     //全局函数类内实现
//     friend void printPerson(Person<T1, T2> p)
//     {
//         cout << "Name: " << p.m_Name << endl << "Age: " << p.m_Age << endl; 
//     }

//     friend void printPerson2<>(Person<T1, T2> p);
// public:
//     Person(T1 name, T2 age)
//     {
//         this->m_Name = name;
//         this->m_Age = age;
//     }

// private:

//     T1 m_Name;
//     T2 m_Age;
// };


// void test1()
// {
//     Person<string, int> p("Tom", 20);

//     printPerson(p);
//     printPerson2(p);
// }


// int main()
// {
//     test1();

//     return 0;
// }

// #include <iostream>
// #include "MyArray.hpp"
// using namespace std;

// void printIntArray(MyArray<int>& arr)
// {

//     for (int i = 0; i < arr.getSize(); i++) 
//     {
//         cout << arr[i] << endl;    
//     }
// }


// void test1()
// {
//     MyArray <int>arr1(5);
    
//     for (int i = 0; i < 5; i++)
//     {
//         //利用尾插法向数组中插入数据
//         arr1.Push_Back(i);
//     }
    
//     cout << "arr1的打印输出: " << endl; 
    
//     printIntArray(arr1);
//     cout << "arr1的容量为: " << arr1.getCapacity() << endl;
//     cout << "arr1的大小为: " << arr1.getSize() << endl;

//     MyArray <int>arr2(arr1);
//     cout << "arr2的打印输出: " << endl;
//     printIntArray(arr2);

//     cout << "arr2的容量为: " << arr2.getCapacity() << endl;
//     cout << "arr2的大小为: " << arr2.getSize() << endl;
// }

// class Person
// {
// public:
//     Person();
//     Person(string name, int age)
//     {
//         this->m_Name = name;
//         this->m_Age = age;
//     }

//     string m_Name;
//     int m_Age;
// };

// void printPersonArray(MyArray<Person>& arr)
// {
//     for (int i = 0; i < arr.getSize(); i++)
//     {
//         cout << "Name: " << arr[i].m_Name << endl << "Age: " << arr[i].m_Age << endl;
//     }
// }

// void test2()
// {
//     MyArray<Person> arr(10);

//     Person p1("wukong", 999);
//     Person p2("hanxin", 20);
//     Person p3("daji", 20);
//     Person p4("zhaoyun", 25);
//     Person p5("anqila", 27);
    
//     arr.Push_Back(p1);

//     arr.Push_Back(p2);
    
//     arr.Push_Back(p3);
    
//     arr.Push_Back(p4);

//     arr.Push_Back(p5);

//     printPersonArray(arr);

//     cout << "arr容量为: " << arr.getCapacity() << endl;
//     cout << "arr大小为: " << arr.getSize() << endl;
// }  

// int main()
// {
//     test1();
//     test2();
//     return 0;
// }


