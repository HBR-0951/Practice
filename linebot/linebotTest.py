from flask import Flask
app = Flask(__name__)

from flask import request, abort
from linebot import LineBotApi,WebhookHandler
from linebot.exceptions import InvalidSignatureError
from linebot.models import MessageEvent,TextMessage,TextSendMessage

line_bot_api = LineBotApi(
    "Zxha2EBKJYtwmf0ZgTjc/Ol8RM3ekFn2k43jwmXA7KeCDK01QgJ03xAs5Q5y6lI4JyULiDa1TrYdVi1laLZDiT590J+8Uo70u65u+oWkxUdThI3IGOOOY0e9eS2c4vMKqbXsOueS5WRwZIsewX1xywdB04t89/1O/w1cDnyilFU=")
handler = WebhookHandler("093fc004f75a32c515714353610a3547")

@app.route('/callback',methods=['Post'])
def callback():
    signature = request.headers['X-Line-Signature']
    body = request.get_data(as_text=True)
    try:
        handler.handle(body,signature)
    except InvalidSignatureError:
        abort(400)
    return 'OK'

@handler.add(MessageEvent,message=TextMessage)
def handle_message(event):
    line_bot_api.reply_message(event.reply_token,
        TextSendMessage(text=event.message.text))
    

if __name__ == '__main__':
    app.run()
