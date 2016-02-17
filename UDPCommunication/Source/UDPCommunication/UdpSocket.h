// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "NetworkProtocolInterface.h"
#include "UdpSocket.generated.h"

/**
 * 
 */
UCLASS()
class UDPCOMMUNICATION_API UUdpSocket : public UObject
{
	GENERATED_BODY()
	
public:
	UUdpSocket();
	UUdpSocket(const FObjectInitializer& ObjectInitializer);

public:
	/**
	* ����������
	* @param Ip IP�A�h���X
	* @param Port �|�[�g�ԍ�
	* @param Protocol �v���g�R��
	*/
	bool Init(const FString& Ip, int32 Port, INetworkProtocolInterface* Protocol);

	/**
	* �I������
	*/
	void Shutdown();

private:
	/**
	* �\�P�b�g���쐬
	*/
	bool CreateSocket();

	/**
	* �\�P�b�g���폜
	*/
	void DeleteSocket();

	/**
	* ��M�҂��쐬
	*/
	bool CreateReceiver();

	/**
	* ��M�҂��폜
	*/
	void DeleteReceiver();
	
	/**
	* �f�[�^�󂯎��R�[���o�b�N
	* @param Reader �ǂݎ��f�[�^
	* @param Sender ���M��
	*/
	void OnDataReceived(const FArrayReaderPtr& Reader, const FIPv4Endpoint& Sender);

private:
	FString Ip;
	FIPv4Address IpAddress;
	int32 Port;
	INetworkProtocolInterface* Protocol;

	FSocket* Socket;
	FUdpSocketReceiver* Receiver;
};
