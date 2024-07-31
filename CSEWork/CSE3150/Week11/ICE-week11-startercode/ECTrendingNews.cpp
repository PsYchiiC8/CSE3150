#include "ECTrendingNews.h"

#include <vector>
#include <algorithm>

// Your code goes here
// pay-per click subscriber
void ECPayPerClickSubscriber :: Update()
{
    news.ReceivePayment(1);
}

void ECContractSubscriber :: Update()
{
}

// Contract subscriber
ECContractSubscriber :: ECContractSubscriber(ECTrendingNews &news) : news(news)
{
}

// This is the subject
ECTrendingNews :: ECTrendingNews() : rev(0)
{

}
ECTrendingNews :: ~ECTrendingNews()
{
}

// add a subscriber
void ECTrendingNews :: Subscribe(ECSubscriber *pSub)
{
    ReceivePayment(pSub->ContractCost());
    this->subs.push_back(pSub);
}
// remove a subscriber
void ECTrendingNews :: UnSubscribe(ECSubscriber *pSub)
{
    this->subs.erase(std::remove(subs.begin(), subs.end() , pSub), subs.end());
}
// Notify news is available for view
void ECTrendingNews :: Notify()
{
    for(auto x: subs)
    {
        x->Update();
    }
}
// receive payment (assume in whole dollar)
void ECTrendingNews :: ReceivePayment(int amount)
{
    this->rev += amount;
}
        
