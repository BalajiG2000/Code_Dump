const puppeteer = require('puppeteer')

async function search(){
    const browser = await puppeteer.launch({headless: false})
    const page = browser.newPage();
    await page.goto('www.google.com')
    const tBox = document.querySelector('')
}