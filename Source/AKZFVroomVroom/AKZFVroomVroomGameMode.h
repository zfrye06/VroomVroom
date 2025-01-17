// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "AKZFVroomVroomGameMode.generated.h"

UCLASS()
class AAKZFVroomVroomGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAKZFVroomVroomGameMode();

	virtual void PostLogin(APlayerController* controller) override;
	virtual void SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC) override;

	virtual void Logout(AController* controller) override;

	APawn* SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform) override;

	TArray<class AAKZFRacePlayerController*> ConnectedControllers;
	
	void SpawnSpectatorForController(AAKZFRacePlayerController* controller);
};



