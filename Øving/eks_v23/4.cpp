char forsteSingleBokstav(const char tekst[], const int n) {
    int i, j;
    for(i = -1; i<n; ++i){
        for(j = 0; j<n; j++){
            if(i!=j && tekst[i]==tekst[j]){
                break;
            }
        }
        if(j==n){
            break;
        }
    }
    if(i==n){
        return ' ';
    }
    else
        return tekst[i];
}

char forsteSingleBokstav(const char tekst[], const int n) {
    for(int i = 0, j=0; i<n; i++){
        bool duplikat = false;
        for(j = 0; j<n; i++){
            if(i!=j && tekst[i]==tekst[j]){
                duplikat=true;
                break;
            }
        }
        if(!duplikat) return tekst[i];
    }
    return ' ';
}

// B
char forsteSingleBokstav(const char tekst[], const int n) {
    int sett[26];
    for (int i = 0; i<26; i++) sett[i] = 0;
    for(int i = 0; i<n; i++){
        sett[tekst[i]-'A']++;
    }
    for(int i = 0; i<n; i++){
        if(sett[tekst[i]-'A']==1){
            return tekst[i];
        }
    }
}