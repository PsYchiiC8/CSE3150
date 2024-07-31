#ifndef EC_TRANDING_NEWS_H
#define EC_TRANDING_NEWS_H


#include <vector>

class ECTrendingNews;

// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
    virtual void Update() = 0;
    virtual int ContractCost() const = 0;
};

// pay-per click subscriber
class ECPayPerClickSubscriber : public ECSubscriber
{
public:
	ECPayPerClickSubscriber(ECTrendingNews &news) : news(news) {};
	~ECPayPerClickSubscriber() {};
	void Update();
	int ContractCost() const {return 0;};

private:
	ECTrendingNews &news;
};

// Contract subscriber
class ECContractSubscriber : public ECSubscriber
{
public:
	ECContractSubscriber(ECTrendingNews &news);
	~ECContractSubscriber() {};
	void Update();
	int ContractCost() const {return 100;};

private:
	ECTrendingNews &news;
};

// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews();
	~ECTrendingNews();
	// add a subscriber
	void Subscribe(ECSubscriber *pSub);
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub);
	// Notify news is available for view
	void Notify();
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount);
	// Get total revenue received
	int GetTotRevenue() const {return rev;}
	
private:
	int rev;
	std::vector<ECSubscriber *> subs;
};


#endif
