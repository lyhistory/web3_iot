//
// Created by Okada, Takahiro on 2018/02/04.
//

#ifndef ARDUINO_WEB3_WEB3_H
#define ARDUINO_WEB3_WEB3_H

typedef unsigned char BYTE;
#define ETHERS_PRIVATEKEY_LENGTH       32
#define ETHERS_PUBLICKEY_LENGTH        64
#define ETHERS_ADDRESS_LENGTH          20
#define ETHERS_KECCAK256_LENGTH        32
#define ETHERS_SIGNATURE_LENGTH        65

#include "stdint.h"
#include <string>

using namespace std;

class Web3 {
public:
    Web3(const string* _host, const string* _path);
    string Web3ClientVersion();
    string Web3Sha3(const string* data);
    int NetVersion();
    bool NetListening();
    int NetPeerCount();
    double EthProtocolVersion();
    bool EthSyncing();
    bool EthMining();
    double EthHashrate();
    long long int EthGasPrice();
    void EthAccounts(char** array, int size);
    int EthBlockNumber();
    long long int EthGetBalance(const string* address);
    int EthGetTransactionCount(const string* address);
    string EthViewCall(const string* data, const char* to);

    string EthCall(const string* from, const char* to, long gas, long gasPrice, const string* value, const string* data);
    string EthSendSignedTransaction(const string* data, const uint32_t dataLen);

    static const char* getDAppCode();

private:
    string exec(const string* data);
    string generateJson(const string* method, const string* params);
    int getInt(const string* json);
    long getLong(const string* json);
    long long int getLongLong(const string* json);
    double getDouble(const string* json);
    bool getBool(const string* json);
    string getString(const string* json);

private:
    const string* host;
    const string* path;


};

#endif //ARDUINO_WEB3_WEB3_H
