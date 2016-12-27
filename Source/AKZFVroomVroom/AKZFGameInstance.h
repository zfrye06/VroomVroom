// Copyright Aaron Karras and Zachary Frye

#pragma once

#include "Engine/GameInstance.h"
#include "AKZFGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class AKZFVROOMVROOM_API UAKZFGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UAKZFGameInstance();

	UFUNCTION(BlueprintCallable, Category="Friends")
	TArray<FString> GetFriendNames(int PlayerId);


	UFUNCTION(BlueprintCallable, Category="Online|Session")
	void ExitSession();

	/* Begins hosting a session */
	UFUNCTION(BlueprintCallable, Category="Online|Session")
	bool HostSession( FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);

	/* Create session delegate, will be bound to in the constructor to recieve created 
		session and forward onto OnCreate Sesssion which will then start the session.*/
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/* Start session delegate, should be initialized in the constructor and
		binds to the OnStartOnlineGameComplete method. */
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;

	/* Handles for our reigstered delegates. So precious. */
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;

	TSharedPtr<class FOnlineSessionSettings> SessionSettings;
	/* Recieves the newly created session, if it was succesful this will then start the session. */
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	/* Recieves the started session, and if successful takes the player to the lobby with listen enabled */
	virtual void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);

	/* Searches for available sessions */
	void FindSessions(FName SessionName, bool bIsLAN, bool bIsPrescense);

	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;

	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	void OnFindSessionsComplete(bool bWasSuccessful);
	
	bool JoinSession(FName SessionName, const FOnlineSessionSearchResult& SearchResult);

	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;

	FDelegateHandle OnJoinSessionCompleteDelegateHandle;

	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnSessionDestroyCompleteDelegateHandle;

	/* Destroys the session */
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

};