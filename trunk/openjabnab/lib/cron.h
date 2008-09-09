#ifndef _CRON_H_
#define _CRON_H_

#include "global.h"
#include <QObject>
#include <QVector>

class PluginInterface;

typedef struct {
	PluginInterface * plugin;
	unsigned int interval; // in min
	unsigned int id;
	unsigned int next_run; // in seconds since 1970-01-01T00:00:00
} CronElement;

class OJN_EXPORT Cron : public QObject
{
	Q_OBJECT
	
public:
	static bool Register(PluginInterface *, unsigned int interval, unsigned int offsetH, unsigned int offsetM, unsigned int id = 0);
	static void Unregister(PluginInterface *, unsigned int id);
	static void UnregisterAll(PluginInterface *);

private slots:
	void OnTimer();
	
private:
	Cron();
	static Cron& Instance();
	QVector<CronElement> CronElements;
};

#endif