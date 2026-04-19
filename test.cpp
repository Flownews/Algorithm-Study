#include <cmath>
#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // 定义变量保存用户输入
    double monthly_invest; // 每月定投金额
    double annual_rate;    // 年化收益率（%）
    int years;             // 定投年限

    // 欢迎界面和输入提示
    cout << "=====================================\n";
    cout << "    定投本息总和计算器\n";
    cout << "=====================================\n";
    cout << "请输入每月定投金额（元）：";
    cin >> monthly_invest;
    cout << "请输入年化收益率（%）：";
    cin >> annual_rate;
    cout << "请输入定投年限（年）：";
    cin >> years;

    // 将年化收益率转为月化收益率
    double monthly_rate = annual_rate / 100 / 12;

    // 计算总月数
    int total_months = years * 12;
    double total_amount = 0.0;

    // 计算公式：终值 = 每期定投金额 × [(1 + 月收益率)^(期数) - 1] / 月收益率
    if (monthly_rate > 0) {
        total_amount = monthly_invest * (pow(1 + monthly_rate, total_months) - 1) / monthly_rate;
    } else {
        // 若收益率为零，仅为本金累加
        total_amount = monthly_invest * total_months;
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2);
    cout << "-------------------------------------\n";
    cout << "定投" << years << "年后的本息总和为：" << total_amount << " 元" << endl;
    cout << "祝您投资顺利，财源广进！" << endl;
    cout << "=====================================\n";

    return 0;
}