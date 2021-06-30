#include <memory>
#include <iostream>

class Foo
{
public:
    Foo(int x)
    {
        x_ = x;
    }

    ~Foo() { std::cout << "~Foo\n"; }

    int x_;
};

class Test
{
public:
    Test(int x)
    {
        x_ = x;
    }

    ~Test() { std::cout << "~Test\n"; }

    int get() { return x_; }

    int x_;
    std::shared_ptr<Foo> fooSptr;
};

void scopetest(std::shared_ptr<Test> SPtr)
{
    std::cout << "in scopetest use count: " << SPtr.use_count() << std::endl;
}

int main(int argc, char *argv[])
{
    /*
    // test nrmal pointer
    Test *t = new Test(1);
    std::cout << t->get() << std::endl;
    delete t;
    */
    
    // multi shared pointer counter
    std::shared_ptr<Test> tSPtr(new Test(1));
    std::shared_ptr<Test> tSPtrB;
    tSPtrB = tSPtr;
    std::cout << "in main use count:      " << tSPtr.use_count() << std::endl;
    scopetest(tSPtr);
    std::cout << "in main Test x value:   " << tSPtr->get() << std::endl;

    /*
    // test non kosher local pointer copy to shared pointer
    Test *tPtr = new Test(1);
    std::shared_ptr<Test> tSPtr(tPtr);
    std::cout << tPtr->get() << std::endl;
    */

    return 0;
}
