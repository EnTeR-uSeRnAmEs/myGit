var result = [];
async function sleep(interval) {
    return new Promise(resolve => {
        setTimeout(resolve, interval);
    })
}
// parent.document.getElementById('foemIframe').contentWindow.document.getElementById('username').value = '21122782';
document.getElementById('username').value = '21122782';
document.getElementById('password').value = '20030307Love';
document.getElementById('submit-button').click();
sleep(1000);
document.evaluate('//*[@id="lnkReport"]', document).iterateNext().click();
completion(result);