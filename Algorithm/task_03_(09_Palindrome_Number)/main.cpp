// 9. Число-палиндром
// Дано целое число x, вернуть, trueесли xэто
// палиндром
// , и falseв противном случае .

// Пример 1:

// Ввод: x = 121
//  Вывод: true
//  Пояснение: 121 читается как 121 слева направо и справа налево.
// Пример 2:

// Ввод: x = -121
//  Вывод: false
//  Пояснение: Слева направо читается как -121. Справа налево становится 121-. Поэтому это не палиндром.
// Пример 3:

// Ввод: x = 10
//  Вывод: false
//  Пояснение: Читает 01 справа налево. Следовательно, это не палиндром.

// Ограничения:

// -231 <= x <= 231 - 1

// Продолжение: Можете ли вы решить эту задачу, не преобразуя целое число в строку?
#include <cassert>
#include <string>
// #include <deque>

class Solution {
   public:
    bool isPalindrome(int x) {

        if (x != 0) {
        if (x < 0 || x % 10 == 0 ) return false;
        if (x > 0 && x <= 9) return true;
        } else { return true; }
        
        int i = 0;
        int revers = 0;
        while (x > 0 && i < 5) {
            if (x == revers) return true;
            revers = revers * 10 + x % 10;
            if (x == revers) return true;
            x /= 10;
            ++i;
        }
        if (x == revers) return true;
        return false;
    }
};

int main() {
    Solution x;
    {assert(x.isPalindrome(1234567899) == false);}
    {assert(x.isPalindrome(1234554321) == true);}
    {assert(x.isPalindrome(11) == true);}
    {assert(x.isPalindrome(123) == false);}
    {assert(x.isPalindrome(12345) == false);}
    {assert(x.isPalindrome(1256521) == true);}
    {assert(x.isPalindrome(121) == true);}
    {assert(x.isPalindrome(-121) == false);}
    {assert(x.isPalindrome(10) == false);}
    {assert(x.isPalindrome(121) == true);}
}