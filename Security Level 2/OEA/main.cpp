#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;

string readCipherFile(int n)
{
    cout<<"Enter the address of the encrypted file:\n";
    string fileAddress;
    cin>>fileAddress;
    cout<<"Reading File..."<<endl;
    fstream cipherTextFile;
    string cipherText;
    cipherTextFile.open(fileAddress , ios::in);
    if(cipherTextFile.fail())
	{
		cout<<"Error opening File!";
		abort();
	}
	char temp;
    cipherTextFile.seekg(n);
	while(!cipherTextFile.eof())
	{
		cipherTextFile.get(temp);
		cipherText+=temp;
	}
	cipherTextFile.close();
	cipherText.erase(cipherText.size()-n-1,n+1);
    cout<<"Done read encrypted text."<<endl;
	return cipherText;
}

void Fencrypt()
{
    cout<<"Starting cryptography..."<<endl;
    //--------------------------------------file reader
    cout<<"Enter File address:\n";
    string fileAddress;
    cin>>fileAddress;
    cout<<"Reading Plain Text..."<<endl;
    string plain;
    fstream plainText;
    plainText.open(fileAddress , ios::in);
    if(plainText.fail())
	{
		cout<<"Error opening File!";
		abort();
	}
	char te;
	while(!plainText.eof())
	{
		plainText.get(te);
		plain+=te;
	}
	plainText.close();
	plain.erase(plain.size()-1,1); // for erase last character
	int textSize=plain.size();
	cout<<"Done read plain text."<<endl;
    //--------------------------------------file reader

    //--------------------------------------key reader
    int keySize;
    string key;
    string keyAddress;
    cout<<"Please enter key file address:\n";
    cin>>keyAddress;
    cout<<"Reading key..."<<endl;
    keySize = 0;
    int weightKey=0;
    fstream keyFile;
    keyFile.open(keyAddress , ios::in);
    if(keyFile.fail())
	{
		cout<<"Error opening  Key File!";
		abort();
	}
	char temp;
	while(!keyFile.eof())
	{
		keyFile>>temp;
		weightKey+=temp;
        keySize++;
        key+=temp;
	}
	keyFile.close();
    cout<<"Done read key."<<endl;
    //-----------------------------------------
   	int masterKey=(weightKey*2)+(keySize*(keySize+textSize));
    string se="";
    string so="";
    string sc="";
    fstream cipherTextFile;
    cipherTextFile.open("OE.A" , ios::out);
    if(cipherTextFile.fail())
    {
        cout<<"Error !";
        abort();
    }
    for(int i=0,j=0;i<weightKey%10;i++,j++)
    {
        if(key[j] % 2 == 0)
            cipherTextFile<<1;
        else
            cipherTextFile<<0;
        if(j==keySize)
            j=0;
    }
    for(int i=0;i<textSize;i++)
	{
		if(plain[i]%2==0)
		{
		    if(se=="")
                se+=plain[i]-masterKey;
            else
                se+=plain[i]+se[se.size()-1];
			sc+="1";
		}
		else
		{
		    if(so=="")
                so+=plain[i]+masterKey;
            else
                so+=plain[i]-so[so.size()-1];
			sc+="0";
		}
	}
	cipherTextFile<<sc;
	cipherTextFile<<se;
	cipherTextFile<<so;
	char tem;
	for(int i=0,j=0;i<weightKey%10;i++,j++)
    {
        tem=key[j]+masterKey;
        cipherTextFile<<tem;
        if(j==keySize)
            j=0;
    }
    cipherTextFile.close();
    cout<<"End of cryptography."<<endl;
    cout<<"Your encryption file was saved successfully.\n";
    cout<<"File name => \"OE.A\"\n";
}

void Fdecrypt()
{
    cout<<"Start decrypting..."<<endl;
    //--------------------------------------key reader
    int keySize;
    string key;
    string keyAddress;
    cout<<"Please enter key file address:\n";
    cin>>keyAddress;
    cout<<"Reading key..."<<endl;
    keySize = 0;
    int weightKey=0;
    fstream keyFile;
    keyFile.open(keyAddress , ios::in);
    if(keyFile.fail())
	{
		cout<<"Error opening  Key File!";
		abort();
	}
	char temp;
	while(!keyFile.eof())
	{
		keyFile>>temp;
		weightKey+=temp;
        keySize++;
        key+=temp;
	}
	keyFile.close();
    cout<<"Done read key."<<endl;
    //-----------------------------------------key re

    string cipherText = readCipherFile(weightKey%10);
    string se="";
    string so="";
    string sc="";
    int sizeSC = cipherText.size()/2;
   	int masterKey=(weightKey*2)+(keySize*(keySize+sizeSC));
    int counterSE = 0;
    int i=0,j,k;
    while(i<sizeSC)
    {
		sc+=cipherText[i];
		if(cipherText[i]=='1')
    		counterSE++;
		i++;
    }
    se+=cipherText[i]+masterKey;
    i++;
    while(i<counterSE+sizeSC)
    {
		se+=cipherText[i]-cipherText[i-1];
		i++;
    }
    so+=cipherText[i]-masterKey;
    i++;
    while(i<sizeSC*2)
    {
		so+=cipherText[i]+cipherText[i-1];
		i++;
    }
    cout<<"End of decrypting."<<endl;
    fstream output ("OEA.txt" , ios :: out);
    if(output.fail()){
        cout<<"Error...\n";
        abort();
    }
    cout<<"Your decrypted text:"<<endl;
    for(i=0,k=0,j=0;i<sizeSC;i++)
	{
		if(sc[i]=='0')
		{
			cout<<so[j];
			output<<so[j];
			j++;
		}
		else if(sc[i]=='1')
		{
			cout<<se[k];
			output<<se[k];
			k++;
		}
	}
	output.close();
}

void Tencrypt()
{

    cout<<"Starting cryptography..."<<endl;
    //--------------------------------------file reader
    cout<<"Enter your Text without spaces:\n";
    string plain;
    cin>>plain;
	int textSize=plain.size();
	cout<<"Done read plain text."<<endl;
    //--------------------------------------file reader

    //--------------------------------------key reader
    int keySize;
    string key;
    string keyAddress;
    cout<<"Please enter key file address:\n";
    cin>>keyAddress;
    cout<<"Reading key..."<<endl;
    keySize = 0;
    int weightKey=0;
    fstream keyFile;
    keyFile.open(keyAddress , ios::in);
    if(keyFile.fail())
	{
		cout<<"Error opening  Key File!";
		abort();
	}
	char temp;
	while(!keyFile.eof())
	{
		keyFile>>temp;
		weightKey+=temp;
        keySize++;
        key+=temp;
	}
	keyFile.close();
    cout<<"Done read key."<<endl;
    //-----------------------------------------
   	int masterKey=(weightKey*2)+(keySize*(keySize+textSize));
    string se="";
    string so="";
    string sc="";
    fstream cipherTextFile;
    cipherTextFile.open("OE.A" , ios::out);
    if(cipherTextFile.fail())
    {
        cout<<"Error !";
        abort();
    }
    for(int i=0,j=0;i<weightKey%10;i++,j++)
    {
        if(key[j] % 2 == 0)
            cipherTextFile<<1;
        else
            cipherTextFile<<0;
        if(j==keySize)
            j=0;
    }
    for(int i=0;i<textSize;i++)
	{
		if(plain[i]%2==0)
		{
		    if(se=="")
                se+=plain[i]-masterKey;
            else
                se+=plain[i]+se[se.size()-1];
			sc+="1";
		}
		else
		{
		    if(so=="")
                so+=plain[i]+masterKey;
            else
                so+=plain[i]-so[so.size()-1];
			sc+="0";
		}
	}
	cipherTextFile<<sc;
	cipherTextFile<<se;
	cipherTextFile<<so;
	char tem;
	for(int i=0,j=0;i<weightKey%10;i++,j++)
    {
        tem=key[j]+masterKey;
        cipherTextFile<<tem;
        if(j==keySize)
            j=0;
    }
    cipherTextFile.close();
    cout<<"End of cryptography."<<endl;
    cout<<"Your encryption file was saved successfully.\n";
    cout<<"File name => \"OE.A\"\n";
}

void menu()
{
    int item;
    cout<<"Please select an item:\n";
    cout<<"1.Encrypt\n2.Decrypt\n0.Exit\n";
    cin>>item;
    switch(item){
    case 1:
        item=0;
        cout<<"1.Encrypt a Text\n2.Encrypt a File\n0.Exit\n";
        cin>>item;
        if(item == 1)
            Tencrypt();
        else if (item == 2)
            Fencrypt();
        else
            abort();
        break;

    case 2:
            Fdecrypt();
        break;

    default:
        abort();
    }
}
int main()
{
    menu();
    return 0;
}
