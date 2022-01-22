int rim() {
    string s;
    cout << "Введите число в римской СС: ";
    cin >> s;
    int* a = new int[s.size() + 1];
    a[s.size()] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'I') { int k = 1; a[i] = k; }
        else
            if (s[i] == 'V') { int k = 5; a[i] = k; }
            else
                if (s[i] == 'X') { int k = 10; a[i] = k; }
                else
                    if (s[i] == 'L') { int k = 50; a[i] = k; }
                    else
                        if (s[i] == 'C') { int k = 100; a[i] = k; }
                        else
                            if (s[i] == 'D') { int k = 500; a[i] = k; }
                            else
                                if (s[i] == 'M') { int k = 1000; a[i] = k; }
                                else
                                {
                                    cout << "Введённое римское число неверно."; return 0;
                                }
    }
    int k = 1, f = 1;
    for (int i = 0; i < s.size(); i++) {
        if (a[i] == a[i + 1]) k++;
        else k = 1;
        if (a[i] == a[i + 1]) f++;
        else f = 1;
        if (a[i + 2] > a[i] && f > 1) { cout << "Введённое римское число неверно."; return 0; }
        if ((a[i + 1] > a[i] * 10) || ((a[i + 1] == a[i]) && (a[i] == 5 || a[i] == 50 || a[i] == 500)) || (k > 3)) { cout << "Введённое римское число неверно."; return 0; }
    }
    for (int i = 0; i < s.size() + 1; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int sum = 0;
    if (s.size() == 1) sum = a[0];
    for (int i = 0; i < s.size(); i++) {
        if (a[i] < a[i + 1]) { sum += (a[i + 1] - a[i]); i++; }
        else { sum += a[i]; if (i == s.size() - 2) sum += a[s.size()]; }
    }
    cout << "Ответ: " << sum;
}
