import { Injectable } from '@angular/core';
import { Http, RequestOptionsArgs, Headers } from '@angular/http';
import { Observable } from 'rxjs/Observable';
import 'rxjs/Rx'

// Use the wsk cli to get this values with `wsk property get`
const API_HOST = "<REPLACE ME>"  //if running locally use your OpenWhisk host instead of bluemix.net
const API_KEY =  window.btoa('<REPLACE ME>');
const API_NAMESPACE = "<REPLACE ME>"
// The Severless Function name get this value with  `wsk action list`
const API_ACTION = "searchVideoAction"
const API_URL = `https://${API_HOST}/api/v1/namespaces/${API_NAMESPACE}/actions/${API_ACTION}?blocking=true`;

@Injectable()
export class ServerlessService {
  constructor(private http: Http) { }

  load(stream: Observable<any>) {
    const makeRequest = (query: string) => {
      const options: RequestOptionsArgs = {
        headers: new Headers({ 'Authorization': `Basic ${API_KEY}` }),
      };
      return {
        url: API_URL,
        options: options,
        body: { query: query, maxResults: 20 }
      };
    }
    return stream
      .map(inputText => makeRequest(inputText))
      .switchMap(req => this.http.post(req.url, req.body, req.options)
        .map(res => res.json().response))
      .map(response => {
        console.log(response);
        return response.result['items']
      });
  }


}



