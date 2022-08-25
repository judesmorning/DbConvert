#include <QtTest>

// add necessary includes here
#include "../converttool.h"


Q_DECLARE_METATYPE(ConvertTool::CalType)
class MyTest : public QObject
{
    Q_OBJECT

public:
    MyTest();
    ~MyTest();

private slots:
    /*系统测试用例*/
    void initTestCase();    //在第一个测试函数执行之前被调用的初始化函数
    void cleanupTestCase(); //在最后一个测试函数执行完毕之后调用的清理操作
    void init();            //每次执行测试函数之前调用的初始化函数
    void cleanup();         //每次执行完测试函数之后调用的清理操作

    /*自定义测试用例*/
    void test_qtest();      //单次单元测试
    void test_calc();       //与test_calc_data一起组合单元测试
    void test_calc_data();


private:
    ConvertTool* m_tool = nullptr;
};

MyTest::MyTest()
{

}

MyTest::~MyTest()
{

}

void MyTest::initTestCase()
{
    m_tool = new ConvertTool(nullptr);
}

void MyTest::cleanupTestCase()
{
    delete m_tool;
    m_tool = nullptr;
}

void MyTest::init()
{

}

void MyTest::cleanup()
{

}

void MyTest::test_qtest()
{
    //计算运行时间,多次运行测量
#if 0
    QBENCHMARK(m_tool->calc(QString("0"), ConvertTool::CalType_dBm2mW));
#endif

    //计算运行时间,单次运行测量
#if 0
    QBENCHMARK_ONCE(m_tool->calc(QString("0"), ConvertTool::CalType_dBm2mW));
#endif

    //比较是否相等
#if 0
    QCOMPARE(m_tool->calc(QString("0"), ConvertTool::CalType_dBm2mW),  QString("1"));
#endif

    //将下1个QCOMPARE或QVERIFY标记为预期测试,如果预期测试没有通过,可以终止剩余当前单元测试【可设置测试终止或继续】
    //第1个参数为空只打印第2个参数,否则打印异常位置
    //第1个参数为Continue、Abort,表示如果不通过是否继续执行剩余用例
#if 0
    QEXPECT_FAIL("", "Will fix in the next release", Continue);
    QCOMPARE(m_tool->calc(QString("0"), ConvertTool::CalType_dBm2mW),  QString("10"));
#endif
    //强制抛出错误并打印信息
#if 0
    if (5 != 4)
    {
        QFAIL("This test has not been ported to this platform yet.");
    }
#endif

    //创建临时变量,从当前数据表中读取数据
#if 0
    //在data函数中创建
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::newRow("positive value") << 100 << 100;
    //在测试函数中取出
    QFETCH(int, a);
    QFETCH(int, b);
    QCOMPARE(a, b);
#endif

    //创建全局变量,从全局数据表中读取数据,必须有initTestCase_data
#if 0
    //QFETCH_GLOBAL?
#endif

    //从路径获取测试数据
#if 0
    MyXmlParser parser;
    QString input = QFINDTESTDATA("testxml/simple1.xml");
    QVERIFY(parser.parse(input));
#endif

    //停止测试,但不会将失败添加到失败日志
#if 0
    if (4 != 5)
    {
        QSKIP("This test requires the SQLITE database driver");
    }
#endif

    //可替代QFETCH+QCOMPARE的便利写法,不需要QFETCH来生成变量
#if 0
    QTEST(QString("hello").toUpper(), "myString");
#endif

    //与QCOMPARE相似,但重复执行两个值的比较,直到两个值相等或者达到超时时间
#if 0
    QTRY_COMPARE_WITH_TIMEOUT(1, 1, 5);
#endif

    //执行QTRY_COMPARE_WITH_TIMEOUT,并将超时时间设置为5秒
#if 0
    QTRY_COMPARE(1, 1);
#endif

    //判断条件是否为true,如果为true则继续执行测试,否则记录失败日志并且不再执行单元测试
#if 0
    QVERIFY(1+1==2);
#endif

    //与QVERIFY相似,但可以自定义失败日志
#if 0
    QVERIFY2(1+1==2, "A breach in basic arithmetic occurred.");
#endif

    //与QVERIFY相似,但重复执行条件的判断,直到条件为true或者达到超时时间
#if 0
    QTRY_VERIFY_WITH_TIMEOUT(1+1==2, 5);
#endif

    //执行QTRY_VERIFY_WITH_TIMEOUT,并将超时时间设置为5秒
#if 0
    QTRY_VERIFY(1+1==2);
#endif

    //与QVERIFY2相似,但重复执行条件的判断,直到条件为true或者达到超时时间
#if 0
    QTRY_VERIFY2_WITH_TIMEOUT(3>2, "this is log msg", 5);
#endif

    //执行QTRY_VERIFY2_WITH_TIMEOUT,并将超时时间设置为5秒
#if 0
    QTRY_VERIFY2(3>2, "this is log msg");
#endif

    //执行表达式,并判断语句抛出的异常是否与预期异常相等
#if 0
    //QVERIFY_EXCEPTION_THROWN
#endif

    //主动添加警告日志,线程安全
#if 0
    QWARN("msg");
#endif
}

void MyTest::test_calc()
{
    //取出测试数据
    QFETCH(QString, calStr);
    QFETCH(ConvertTool::CalType, type);
    QFETCH(QString, result);
    //测试
    QCOMPARE(m_tool->calc(calStr, type), result);
}

void MyTest::test_calc_data()
{
    /*创建测试参数*/
    QTest::addColumn<QString>("calStr");            //创建第1个入参集合
    QTest::addColumn<ConvertTool::CalType>("type"); //创建第2个入参集合
    QTest::addColumn<QString>("result");            //创建返回值集合

    /*设计用例*/
    QTest::newRow("ok_1") << "0" << ConvertTool::CalType_dBm2mW << "1";
    QTest::newRow("ok_2") << "10" << ConvertTool::CalType_dBm2mW << "10";
    QTest::newRow("ng_1") << "10" << ConvertTool::CalType_dBm2mW << "100";
}



QTEST_APPLESS_MAIN(MyTest)

#include "tst_mytest.moc"
