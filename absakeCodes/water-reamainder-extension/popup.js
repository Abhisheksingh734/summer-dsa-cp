const form = document.getElementById('settingsForm');
const progressCount = document.getElementById('progressCount');
const goalCount = document.getElementById('goalCount');
const addWaterBtn = document.getElementById('addWater');

chrome.storage.sync.get(['interval', 'goal', 'progress'], (data) => {
  document.getElementById('interval').value = data.interval || 60;
  document.getElementById('goal').value = data.goal || 8;
  goalCount.textContent = data.goal || 8;
  progressCount.textContent = data.progress || 0;
});

form.addEventListener('submit', (e) => {
  e.preventDefault();
  const interval = parseInt(document.getElementById('interval').value);
  const goal = parseInt(document.getElementById('goal').value);

  chrome.storage.sync.set({ interval, goal, progress: 0 });
  goalCount.textContent = goal;
  progressCount.textContent = 0;

  // Set the reminder interval
  chrome.runtime.sendMessage({ type: 'setInterval', interval });

  alert('Settings saved!');
});

addWaterBtn.addEventListener('click', () => {
  chrome.storage.sync.get(['progress', 'goal'], (data) => {
    const newProgress = (data.progress || 0) + 1;
    if (newProgress <= data.goal) {
      chrome.storage.sync.set({ progress: newProgress });
      progressCount.textContent = newProgress;
    } else {
      alert('Daily goal already achieved!');
    }
  });
});
