// Copyright Aaron Karras and Zachary Frye

#pragma once

#include "UObject/NoExportTypes.h"
#include "MapData.generated.h"

USTRUCT(Blueprintable)
struct AKZFVROOMVROOM_API FMapInformation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	int MapId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Information")
	FString Url;

	// Map Text Information
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Image")
	UTexture* Preview;
};

/**
 * 
 */
UCLASS()
class AKZFVROOMVROOM_API UMapData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMapInformation> Maps;
	
	
};