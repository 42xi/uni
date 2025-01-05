#include <iostream>
#include <string>
using namespace std;

class AuthenticationResult
{
    bool _c_is_authenticated;
    string _c_username;

public:
    AuthenticationResult(bool is_authenticated, string username = "unauthenticated_user")
        : _c_is_authenticated(is_authenticated), _c_username(username) {}
    string get_username() { return this->_c_username; }
    bool get_authenticated() { return this->_c_is_authenticated; }
};

class IAuthenticationProcedure
{
public:
    virtual AuthenticationResult authenticate() = 0;
    virtual ~IAuthenticationProcedure() {}
};

class MockAuthentication : public IAuthenticationProcedure
{
public:
    AuthenticationResult authenticate() override
    {
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationProcedure
{
    string usrname, pswd;

public:
    AuthenticationResult authenticate() override
    {
        cout << "Username:" << endl;
        cin >> usrname;
        cout << "Password:" << endl;
        cin >> pswd;

        if (usrname == pswd)
        { // Benutzername und Passwort stimmen überein
            return AuthenticationResult(true, usrname);
        }
        else
        { // Authentifizierung fehlgeschlagen
            return AuthenticationResult(false);
        }
    }
};

class Certificate : public IAuthenticationProcedure
{
    string certif;

public:
    AuthenticationResult authenticate() override
    {
        cout << "Zertifikatsaussteller:" << endl;
        cin >> certif;

        if (certif == "hs-esslingen")
        { // Zertifikatsaussteller ist korrekt
            return AuthenticationResult(true, "certificate.owner");
        }
        else
        { // Zertifikatsaussteller ist ungültig
            return AuthenticationResult(false);
        }
    }
};

class Client
{
    IAuthenticationProcedure *_authentication_procedure;

public:
    void set_authentication_procedure(IAuthenticationProcedure *authentication_procedure)
    {
        _authentication_procedure = authentication_procedure;
    }

    void execute()
    {
        AuthenticationResult res = _authentication_procedure->authenticate();
        if (res.get_authenticated())
        {
            cout << "Das Programm wird ausgeführt für " << res.get_username() << "." << endl;
        }
        else
        {
            cout << "Das Programm konnte nicht ausgeführt werden." << endl;
        }
    }
};

int main()
{
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure *mock_authentication = new MockAuthentication();
    client.set_authentication_procedure(mock_authentication);
    client.execute();
    delete mock_authentication;

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure *username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();
    delete username_password;

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure *certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    delete certificate;

    return 0;
}
