// Copyright Aaron Karras and Zachary Frye

#pragma once

#include "GameFramework/GameModeBase.h"
#include "Data/MapData.h"
#include "AKZFLobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AKZFVROOMVROOM_API AAKZFLobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AAKZFLobbyGameMode();
	
	UFUNCTION(BlueprintCallable, Category="Game")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category="Data")
	TArray<FMapInformation> LoadMaps();

	virtual void PostLogin(APlayerController* controller) override;
	virtual void Logout(AController* controller) override;
	TArray<AAKZFLobbyController*> ConnectedPlayers;
};
