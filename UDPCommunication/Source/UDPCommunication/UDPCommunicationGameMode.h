// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "NetworkProtocolTransform.h"
#include "NetworkProtocolColor.h"
#include "UDPCommunicationGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UDPCOMMUNICATION_API AUDPCommunicationGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AUDPCommunicationGameMode();
	AUDPCommunicationGameMode(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
	/**
	* ����������
	*/
	virtual void Init();

	/**
	* �I������
	*/
	virtual void Shutdown();

	/**
	* Transform�v���g�R���擾
	*/
	UFUNCTION(BlueprintPure, Category = "Network")
		UNetworkProtocolTransform* GetTransformProtocol() const { return TransformProtocol; }

	/**
	* Transform�v���g�R���擾
	*/
	UFUNCTION(BlueprintPure, Category = "Network")
		UNetworkProtocolColor* GetColorProtocol() const { return ColorProtocol; }
private:
	/**
	* Transform�v���g�R������������
	*/
	bool InitTransformProtocol();

	/**
	* Transform�v���g�R���I������
	*/
	void ShutdownTransformProtocol();

	/**
	* Color�v���g�R������������
	*/
	bool InitColorProtocol();

	/**
	* Color�v���g�R���I������
	*/
	void ShutdownColorProtocol();

private:
	/** Transform�v���g�R�� */
	UPROPERTY()
	class UNetworkProtocolTransform* TransformProtocol;

	/** Color�v���g�R�� */
	UPROPERTY()
	class UNetworkProtocolColor* ColorProtocol;

	/** Transform�\�P�b�g */
	UPROPERTY()
	class UUdpSocket* TransformUdpSocket;

	/** Color�\�P�b�g */
	UPROPERTY()
	class UUdpSocket* ColorUdpSocket;
	
	
};
