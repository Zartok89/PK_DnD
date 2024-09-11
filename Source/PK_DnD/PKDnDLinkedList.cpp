#include "PKDnDLinkedList.h"
#include "PKDnDNodeObject.h"

void UPKDnDLinkedList::Append(FString Data)
{
	mData = Data;

	UPKDnDNodeObject* NewNode = NewObject<UPKDnDNodeObject>(GetTransientPackage());  
    NewNode->Node(mData);

	if (IsValid(Head))
	{
		CurrentNode = Head;
		while (IsValid(CurrentNode->NextNode))
		{
			CurrentNode = CurrentNode->NextNode;
		}
		CurrentNode->NextNode = NewNode;
	}
	else
	{
		Head = NewNode;
	}
}

void UPKDnDLinkedList::Prepend(FString Data)
{
	mData = Data;

	UPKDnDNodeObject* NewNode = NewObject<UPKDnDNodeObject>(GetTransientPackage());  
    NewNode->Node(mData);

	if (IsValid(Head))
	{
		CurrentNode = NewNode;
		CurrentNode->NextNode = Head;
		Head = CurrentNode;
	}
	else
	{
		Head = NewNode;
	}
}

void UPKDnDLinkedList::DeleteWithValue(FString Data)
{
	mData = Data;

	if (IsValid(Head))
	{
		if(Head->mData == mData)
		{
			if(IsValid(Head->NextNode))
			{
				Head = Head->NextNode;
			}
			else
			{
				Head = nullptr;
			}
		}
		else
		{
			CurrentNode = Head;
			while(IsValid(CurrentNode->NextNode))
			{
				if(CurrentNode->NextNode->mData == mData)
				{
					if(IsValid(CurrentNode->NextNode->NextNode))
					{
						CurrentNode->NextNode = CurrentNode->NextNode->NextNode;
					}
					else
					{
						CurrentNode->NextNode = nullptr;
					}
				}
				else
				{
					CurrentNode = CurrentNode->NextNode;
				}
			}
		}
	}



	///*-----------------------------------
	//Chat GPT Improved Code
	//-----------------------------------*/
	//
	//// If the list is empty, there's nothing to delete  
 //   if (!IsValid(Head))  
 //       return;  

 //   // Handle the case where the head node needs to be deleted  
 //   while (IsValid(Head) && Head->mData == Data)  
 //   {  
 //       Head = Head->NextNode;  
 //   }  

 //   // If the list becomes empty after removing head nodes  
 //   if (!IsValid(Head))  
 //       return;  

 //   // Use two pointers to find and remove nodes with the matching data  
 //   CurrentNode = Head;  
 //   while (IsValid(CurrentNode->NextNode))  
 //   {  
 //       if (CurrentNode->NextNode->mData == Data)  
 //       {  
 //           CurrentNode->NextNode = CurrentNode->NextNode->NextNode;  
 //       }  
 //       else  
 //       {  
 //           CurrentNode = CurrentNode->NextNode;  
 //       }  
 //   }  
}

void UPKDnDLinkedList::PrintList()
{
	if (IsValid(Head))
	{
		CurrentNode = Head;
		while (IsValid(CurrentNode))
		{
			FString NodeData = CurrentNode->mData;
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("%s"), *NodeData));
			CurrentNode = CurrentNode->NextNode;	
		}
	}
}