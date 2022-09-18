async function authenticatedFetch(uri, options) {
	var AppBridge = window['app-bridge'];
	var app = AppBridge.createApp({
		apiKey: '',
		host: ''
	});
	var fetchFunction = window['app-bridge-utils'].authenticatedFetch(app);
	var response = await fetchFunction(uri, options);
	var headers = response.headers;
	if (headers.get("X-Shopify-API-Request-Failure-Reauthorize")
		=== "1") {
		var authUrlHeader = headers.get(
			"X-Shopify-API-Request-Failure-Reauthorize-Url")
			|| `/api/auth`;
		var Redirect = AppBridge.actions.Redirect;
		Redirect.create(app).dispatch(Redirect.Action.REMOTE,
			authUrlHeader.startsWith("/")
			? `https://${window.location.host}${authUrlHeader}`
			: authUrlHeader
		);
	}
	return response;
}
