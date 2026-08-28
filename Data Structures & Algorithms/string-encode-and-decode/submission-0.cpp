class Solution {
public:

string encode_a_string(string s){

    //std::cout<<"[encode_a_string] input s= "<<s<<"\n";

    size_t length_i = s.length();
    string length_s = to_string(length_i);
    string prefix;

    if (length_i>=100)    { prefix = "";}
    else if (length_i>=10){ prefix = "0";}
    else                  { prefix = "00";}

    prefix.append(length_s);
    prefix.append(s);
    //std::cout<<"[encode_a_string] result = "<<prefix<<"\n";
    return prefix;
}


string encode(vector<string>& strs) {

    const size_t n = strs.size();
    //std::cout<<"[encode] input n= "<<n<<"\n";

    string encoded_strs{};
    //encoded.reserve TODO
    for (auto s: strs){
        encoded_strs.append(encode_a_string(s));
    }

    return encoded_strs;
}

vector<string> decode(string s) {

    vector<string> decoded{};//strings are not even init here

    size_t pos=0;
    size_t end = s.length();

    while (pos<end){
        string length_s{}; 
        length_s+=s[pos];
        length_s+=s[pos+1];
        length_s+=s[pos+2];
        pos+=3;
        
        //std::cout<<"[decode] length_s = "<<length_s<<"\n";
        size_t length_i = stoul(length_s);
        //std::cout<<"[decode] length_i = "<<length_i<<"\n";

        //rings a bell uh you cant emplace in non constructed spot
        //decoded[i].append(s.begin()+pos, s.begin()+pos+length_i); <- wrong, assigned to pure bytes
        decoded.emplace_back(s.begin()+pos, s.begin()+pos+length_i);

        //std::cout<<"range= ["<<pos<<","<<pos+length_i<<"]\n";
        pos+=length_i;
    }
    
    return decoded;
}
};
