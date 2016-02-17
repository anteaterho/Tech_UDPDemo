#pragma once 

#include "Networking.h"
#include "NetworkProtocolInterface.generated.h"

UINTERFACE()
class UDPCOMMUNICATION_API UNetworkProtocolInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class UDPCOMMUNICATION_API INetworkProtocolInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	/**
	* �v���g�R���ʃp�[�X����
	*/
	virtual bool Parse(const FArrayReaderPtr& Reader) { return false; }
};