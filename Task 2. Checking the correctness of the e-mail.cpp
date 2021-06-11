/*
    Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.

    Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @.
    Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. 
    Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом, 
    а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:

    !#$%&'*+-/=?^_`{|}~
    Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.

    Примеры

    Корректные адреса:
    simple@example.com
    very.common@example.com
    disposable.style.email.with+symbol@example.com
    other.email-with-hyphen@example.com
    fully-qualified-domain@example.com
    user.name+tag+sorting@example.com (may go to user.name@example.com inbox depending on mail server)
    x@example.com (one-letter local-part)
    example-indeed@strange-example.com
    admin@mailserver1
    example@s.example
    mailhost!username@example.org
    user%example.com@example.org

    Некорректные адреса:
    John..Doe@example.com (две точки не могут идти подряд)
    Abc.example.com (нет символа @)
    A@b@c@example.com (символ @ должен быть только один)
    a"b(c)d,e:f;g<h>i[j\k]l@example.com (присутствуют недопустимые символы)
    1234567890123456789012345678901234567890123456789012345678901234+x@example.com (первая часть длиннее 64 символов)
    i_like_underscore@but_its_not_allow_in _this_part.example.com (во второй части присутствует недопустимый символ «_»)

    Советы и рекомендации
    Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
    Создайте отдельные функции, которые выдают первую и вторую части адреса для их последующего анализа.
    Для валидации отдельных символов внутри части используйте дополнительные строки-словари, состоящие из всех корректных символов для соответствующей части.

    Что оценивается
    Корректные результаты валидации адресов электронной почты. Должны устанавливаться как валидные адреса, так и невалидные.
*/

#include <iostream>
#include <string>
using namespace std;
//function that output first half of the email
string first_half(string szEMail)
{
    // variable number of '@'
    int nAt = 0;
    // return variable
    string szFirstHalfEMail;

    //cheking the correctness of the input first character
    if (szEMail[0] == '@' || szEMail[0] == '.') {
        return "error: incorrect e-mail";
    }
    else {
        szFirstHalfEMail += szEMail[0];
    }
    //chekink and counting all characters
    for (int i = 1; i < szEMail.length(); i++) {    
        if (szEMail[i] == '@') nAt++;
        if (nAt == 0) szFirstHalfEMail += szEMail[i];
    }
    //return first half of the email if correct, else return error message
    if (nAt == 1) {
        return szFirstHalfEMail;
    }
    else {
        return "error: incorrect e-mail";
    }
}

//function that output other half of the email
string other_half(string szEMail) {
    //if first half correct, begining program, else return error meseg
    if (first_half(szEMail) != "error: incorrect e-mail") {
        string szOtherHalfEMail;
        bool bAt = false;

        for (int i = 0; i < szEMail.length(); i++) { 
            if (bAt) szOtherHalfEMail += szEMail[i];
            if (szEMail[i] == '@') bAt = true;
        }
        return szOtherHalfEMail;
    }
    else {
        return "error: incorrect e-mail";
    }
}


int main()
{
    string szEMail;
    cout << "Input e-mail:";
    cin >> szEMail;

    //cout << "First half e-mail: " << first_half(szEMail) << endl;
    //cout << "Second half e-mail: " << other_half(szEMail) << endl;
    
    //составить словарь проверки

    //проверка каждой из половин с помощью "словаря"

}


