// Listen for the message to set the reminder interval
chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.type === 'setInterval') {
      setReminderInterval(message.interval);
    }
  });
  
  // Set the reminder interval and alarm
  function setReminderInterval(minutes) {
    chrome.storage.sync.set({ reminderInterval: minutes }, () => {
      chrome.alarms.clear('waterReminder');
      chrome.alarms.create('waterReminder', {
        periodInMinutes: minutes  // This sets the alarm to repeat every X minutes
      });
    });
  }
  
  // Handle the alarm event
  chrome.alarms.onAlarm.addListener((alarm) => {
    if (alarm.name === 'waterReminder') {
      chrome.notifications.create({
        type: 'basic',
        iconUrl: 'icons/icon48.png',
        title: 'Water Reminder',
        message: 'Time to drink water!',
        priority: 1
      });
    }
  });
  
  // When the extension is installed, set the initial alarm with the default interval
  chrome.runtime.onInstalled.addListener(() => {
    chrome.storage.sync.get('reminderInterval', (data) => {
      const interval = data.reminderInterval || 60;  // Default to 60 minutes if not set
      chrome.alarms.create('waterReminder', { periodInMinutes: interval });
    });
  });
  