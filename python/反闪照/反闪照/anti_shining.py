import websocket
from requests import get
from json import loads
from re import findall
from pprint import pprint
call_api = lambda api_name,**data:loads(get('http://127.0.0.1:5700/'+api_name+'?'+'&'.join(f"{k}={v}" for k,v in data.items())).content)
def on_message(ws,message):
    data = loads(message)
    if data['post_type'] == 'meta_event':
        if data['meta_event_type'] == 'lifecycle':
            print('连接成功!')
    
    elif data['post_type']=='message':
        if 'type=flash' in data['message']:
            print(f"发现来自{data['sender']['nickname']}的闪照")
            url = f"https://gchat.qpic.cn/gchatpic_new/{data['sender']['user_id']}/2640570090-2264725042-{findall('file=(.*?).image',data['message']).pop().upper()}/0?term=3"
            res = call_api("send_msg",user_id=data['self_id'],message=f"[CQ:image,file={url}]")
            print(res)
def on_error(ws,error):
    pass
def on_close(*args):
    pass

from subprocess import PIPE,Popen

def start_listening():
    ws = websocket.WebSocketApp("ws://127.0.0.1:6700",on_message=on_message,on_error=on_error,on_close=on_close)
    while True:
        try:
            ws.run_forever()
        except Exception as e:
            pass

if __name__ == "__main__":
    proc = Popen(['go-cqhttp_windows_amd64.exe','-faststart'])
    start_listening()
